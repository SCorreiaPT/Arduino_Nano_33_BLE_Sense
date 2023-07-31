/*
nRF52840 Microcontroller
- 64 MHz Cortex-M4 with FPU
- 1 MB Flash, 256 KB RAM
- 2.4 GHz Transceiver
- 2 Mbps, 1 Mbps, Long Range
- Bluetooth Low Energy, Bluetooth mesh
- ANT, 802.15.4, Thread, Zigbee
- +8 dBm TX Power
- 128-bit AES CCM, ARM CryptoCell
- UART, SPI, TWI, PDM, I2S, QSPI
- PWM
- 12-bit ADC
- NFC-A
- USB 2.0

Peripherals
- LSM9DS1, 9 axis IMU (The max refresh rate for the accelerometer and gyro is 952Hz and up to 80 Hz for the magnetometer)
- HTS221, Capacitive Digital Humidity & Temperature Sensor
- APDS9960, Advanced gesture detection, proximity detection, digital ambient Light Sense (ALS), and Color Sense (RGBC)
- LPS22HB, Piezoresistive absolute pressure sensor that functions as a digital output barometer
- MP34DT05, Ultra-compact, low-power, omnidirectional, digital MEMS microphone

 * Author: SCorreia
 */ 

#include <Arduino_LSM9DS1.h>	// IMU LSM9DS1 9DOF
/**
  Accelerometer range is set at [-4, +4]g -/+0.122 mg.
  Gyroscope range is set at [-2000, +2000] dps +/-70 mdps.
  Magnetometer range is set at [-400, +400] uT +/-0.014 uT.

  Accelerometer Output data rate is fixed at 104 Hz.
  Gyroscope Output data rate is fixed at 104 Hz.
  Magnetometer Output data rate is fixed at 20 Hz.
**/
  float x, y, z;


void setup()
{
  // Initializes the DEBUG Interface
	Serial.begin(115200);								          // Serial communications for debugging
  delay(3000);
  Serial.println("Arduino Nano BLE Sense...");	// Initialization message

  // set LED pin to Output Mode
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

	// Turn OFF all LEDs
  digitalWrite(LED_BUILTIN, LOW);         
  digitalWrite(LEDR, HIGH);          
  digitalWrite(LEDG, HIGH);        
  digitalWrite(LEDB, HIGH);         
	
	delay(1000);
	
  // LED RED ON, Builtin LED flashing
  digitalWrite(LED_BUILTIN, HIGH);         
  digitalWrite(LEDR, LOW);          
  digitalWrite(LEDG, HIGH);        
  digitalWrite(LEDB, HIGH);   

  delay(1000);

  // LED GREEN ON, Builtin LED flashing
  digitalWrite(LED_BUILTIN, LOW);         
  digitalWrite(LEDR, HIGH);          
  digitalWrite(LEDG, LOW);        
  digitalWrite(LEDB, HIGH);     

  delay(1000);

  // LED BLUE ON, Builtin LED flashing
  digitalWrite(LED_BUILTIN, HIGH);         
  digitalWrite(LEDR, HIGH);          
  digitalWrite(LEDG, HIGH);        
  digitalWrite(LEDB, LOW);    

  delay(1000);

  // LED RGB ON, Builtin LED flashing
  digitalWrite(LED_BUILTIN, LOW);         
  digitalWrite(LEDR, LOW);          
  digitalWrite(LEDG, LOW);        
  digitalWrite(LEDB, LOW); 

  delay(1000);

  // LED RGB OFF, Builtin LED OFF
  digitalWrite(LED_BUILTIN, LOW);         
  digitalWrite(LEDR, HIGH);          
  digitalWrite(LEDG, HIGH);        
  digitalWrite(LEDB, HIGH);  
	
  // Accelerometer Application
	if (!IMU.begin())
	{
		Serial.println("Error initializing IMU sensor [LSM9DS1]");
		Serial.println("Reset needed");
		while(1);									// Block initialization (Reset needed)
	}
	Serial.println("IMU sensor initialized ...");	// Hardware sensor LSM9DS1 initialized
  
  // Acc
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
  
  // Gyro
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");

  Serial.println();

}

void loop()
{

  // LSM9DS1 Inertial Measurement Unit Readings
  Serial.println();
  Serial.println("*** LSM9DS1 Inertial Measurement Unit ***");

  // Reads acceleration in all three directions
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    Serial.println();
    Serial.print("Acceleration in G's =>"); Serial.print('\t');
    Serial.print("X = "); Serial.print(x); Serial.print('\t');
    Serial.print("Y = "); Serial.print(y); Serial.print('\t');
    Serial.print("Z = "); Serial.print(z);
  }

  // Reads angular velocity in all three directions
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);
    Serial.println();
    Serial.print("Gyroscope in degrees/second =>"); Serial.print('\t');
    Serial.print("X = "); Serial.print(x); Serial.print('\t');
    Serial.print("Y = "); Serial.print(y); Serial.print('\t');
    Serial.print("Z = "); Serial.print(z);    
  }

  // read magnetic field in all three directions
  IMU.readMagneticField(x, y, z);
  Serial.println();
  Serial.print("Magnetic Field in uT =>"); Serial.print('\t');
  Serial.print("X = "); Serial.print(x); Serial.print('\t');
  Serial.print("Y = "); Serial.print(y); Serial.print('\t');
  Serial.print("Z = "); Serial.print(z);   

  delay(1000);

}