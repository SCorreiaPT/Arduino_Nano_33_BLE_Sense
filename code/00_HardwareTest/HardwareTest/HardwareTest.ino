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

 * Author: scorr
 */ 

#include <Arduino_LSM9DS1.h>	// IMU LSM9DS1 9DOF




void setup()
{
	Serial.begin(115200);								// Serial communications for debugging
  delay(3000);
	
// set LED pin to output mode
pinMode(LEDR, OUTPUT);
pinMode(LEDG, OUTPUT);
pinMode(LEDB, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);

	Serial.println("Arduino Nano BLE Sense...");	// Initialization message

digitalWrite(LED_BUILTIN, LOW);         // when the central disconnects, turn off the LED
digitalWrite(LEDR, HIGH);          // will turn the LED off
digitalWrite(LEDG, HIGH);        // will turn the LED off
digitalWrite(LEDB, HIGH);         // will turn the LED off
	
	delay(3000);
	
digitalWrite(LED_BUILTIN, HIGH);         // when the central disconnects, turn off the LED
digitalWrite(LEDR, LOW);          // will turn the LED off
digitalWrite(LEDG, LOW);        // will turn the LED off
digitalWrite(LEDB, LOW);         // will turn the LED off
	
	if (!IMU.begin())
	{
		Serial.println("Error initializing IMU sensor [LSM9DS1]");
		Serial.println("Reset needed");
		while(1);									// Block initialization (Reset needed)
	}
	Serial.println("IMU sensor initialized ...");	// Hardware sensor LSM9DS1 initialized
		
}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */

}