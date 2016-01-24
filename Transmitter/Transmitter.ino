#include <util/crc16.h>
#define offsetof(st, m) ((size_t)(&((st *)0)->m))
//Function Declaration

byte crc8(const byte *packet);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
typedef struct DataPacket
{
 uint8_t Altitude;
 uint8_t Temp;
 uint8_t IMU;
 uint8_t GPS;
 uint8_t Pressure;
 uint8_t Pressure1; 
 uint16_t CRC;
} DataPacket;

DataPacket data;



byte crc(struct DataPacket * orig, int len)
{
  unsigned char * raw = (unsigned char *)malloc(len);
  memcpy(raw, &orig, len);
  int crc = 0b1101;
  int c = 4;
  int i;
  raw = raw << c-1;
  for(i = len+c-1; i >= c; i--)
  {
    if((raw >> (i-1)) % 2)
    {
      raw ^= crc << (i-c);
    }
  }  
  return raw;
     
}




void loop() {
  
 
  
  Serial.print(crc(*data, offsetof(DataPacket, CRC)*8));
  
  // put your main code here, to run repeatedly:
  tone(8, 1200, 1000);
  delay(1000);
  noTone(8);
  tone(8,1000, 1000);
  delay(1000);
  noTone(8);
  
}
