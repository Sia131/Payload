// CODE FOR AD7124
#include <SPI.h>
const byte ID = 0b01000101;     // Read value at ID (should be 0x14 or 0x16)
const int chipSelectPin = 10;
const int dataReadyPin = 13;
void setup() {
  // start the SPI library:
  Serial.begin(9600);
  SPI.begin();
  // initalize chip select pins:
  pinMode(dataReadyPin, INPUT);
  pinMode(chipSelectPin, OUTPUT);
// AD7124 operates in SPI mode 3.  The device uses the SPI mode 3, which means
// that the clock signal (SCK) is idle HIGH, and the rising edge of SCLK is the sample edge. The
// data is clocked out on the falling edge and clocked in on the rising edge of the clock signal
// pulse.
  SPI.setDataMode(SPI_MODE3);
  // give the ADC time to set up:
  delay(100);
}
void loop() {
  Serial.print("Value at ID register 0x5: ");
//  writeToRegister(0x51, 1);
  delay(1000);
  Serial.println(readRegister(0x5,8));
  Serial.println("Sent");
  //SCLK idles high
  delay(1000);
}
unsigned int readRegister(byte thisRegister, int numberOfBytes) {  //Read from a register
  byte inByte = 0;
  unsigned int result = 10;
  // take the chip select low to select the device:
  digitalWrite(chipSelectPin, LOW);
  delay(100);
  result = SPI.transfer(0b01000000 || thisRegister); //Send register location
  //Serial.print(result);
  //result = SPI.transfer(0x5);
  Serial.print("\ndata ready? ");
  Serial.println(digitalRead(dataReadyPin));
  // take the chip select high to de-select:
  digitalWrite(chipSelectPin, HIGH);
  delay(100);
  // return the result:
  return (result);
}
void writeToRegister(byte thisRegister, byte thisValue) { //write to a  register
  // take the chip select low to select the device:
  digitalWrite(chipSelectPin, LOW);
  SPI.transfer(thisRegister); //Send register location
  SPI.transfer(thisValue);  //Send value to record into register
  // take the chip select high to de-select:
  digitalWrite(chipSelectPin, HIGH);
}
