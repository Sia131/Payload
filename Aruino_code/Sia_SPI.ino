#include <SPI.h>

const int active_low_SS = 10; 
const int delay_time = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI_init();
}

void loop() {
 uint8_t data = Read_from_register(0x00);
  Serial.println(data);
  delay(delay_time);
  // put your main code here, to run repeatedly:

}

void SPI_init(){
  pinMode(active_low_SS, OUTPUT);
  SPI.setDataMode(SPI_MODE3);
  SPI.begin();
  //Might have to change this to LSBFIRST
}


void SPI_Write(int data){
  //SPI.setDataMode(SPI_MODE3);
  digitalWrite(active_low_SS, LOW);
  SPI.transfer(data);
  digitalWrite(active_low_SS, HIGH);
}


uint8_t SPI_Read(){
  SPI.setDataMode(SPI_MODE2);
  digitalWrite(active_low_SS, LOW);
  uint8_t data =  SPI.transfer(0x00);
  digitalWrite(active_low_SS, HIGH);
  return data;
}





void Write_to_register(uint8_t registers, uint8_t data){
  uint8_t command = (B00 << 6)| (registers);
  SPI_Write(command);
  SPI_Write(data);
}

uint8_t Read_from_register(uint8_t registers){
  uint8_t command  = (B01 << 6) | (registers);
  SPI_Write(command);
  uint8_t data = SPI_Read();
  return data;
}
