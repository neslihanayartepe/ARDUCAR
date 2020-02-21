#include <SoftwareSerial.h> // HC05 BLUETOOTH MODULÜ AYARLARI

SoftwareSerial BTSerial(10, 11); // TX | RX modülün tx'i 10 nolu pin'e rx'i 11 nolu pin

void setup() 
{
pinMode(9, OUTPUT); // bu pinmodüldeki vcc altındaki pine bağlanacak state e 
//bağlanmayacak sadece state pin i boş bırakılacak
digitalWrite(9, HIGH); 
Serial.begin(9600);
Serial.println("Enter AT commands:");
BTSerial.begin(38400); // HC-05 default speed in AT 

}

void loop()
{
// Keep reading from HC-05 and send to Arduino 
// Serial Monitor
if (BTSerial.available())
Serial.write(BTSerial.read());

// Keep reading from Arduino Serial Monitor 
// and send to HC-05
if (Serial.available())
BTSerial.write(Serial.read());
}
