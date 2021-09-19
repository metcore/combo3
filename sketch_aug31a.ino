//RS-485 Modbus Slave (Arduino UNO)

#include<ModbusRtu.h>       //Library for using Modbus in Arduino

#define j3 2 //Define as 2 led1 
#define j4 3 //Define as 5 led2
#define j5 4
#define j6 5

void( * mulai_reset)(void) = 0; 
Modbus bus; 
uint16_t modbus_array[200 ]; //Array initilized with three 0 values

int menit;
int detik;

unsigned long interval = 1000; // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.

int twins;
int ozone;
int oksigen;

void setup() {
  Serial.begin(9600);

  pinMode(j3, OUTPUT);
  pinMode(j4, OUTPUT); //Led1 set as OUTPUT
  pinMode(j5, OUTPUT); //Led2 set as OUTPUT
  pinMode(j6, OUTPUT);
  bus = Modbus(1, 1, 7); //Modbus slave ID as 1 and 1 connected via RS-485 and 7 connected to DE & RE pin of RS-485 Module 
  bus.begin(9600); //Modbus slave baudrate at 9600

  digitalWrite(j3, HIGH);
  digitalWrite(j4, HIGH);
  digitalWrite(j5, HIGH);
  digitalWrite(j6, HIGH);
}

void loop() {

  bus.poll(modbus_array, sizeof(modbus_array) / sizeof(modbus_array[0]));

  if (modbus_array[1] == 0) {
    digitalWrite(j3, HIGH);
    digitalWrite(j4, HIGH);
    digitalWrite(j5, HIGH);
    digitalWrite(j6, HIGH);
  }

  
  if (modbus_array[1]==1) {
    digitalWrite(j3, LOW);
    digitalWrite(j4, LOW);
    digitalWrite(j5, LOW);
    digitalWrite(j6, HIGH);
  }

  if (modbus_array[1]==2) {

    digitalWrite(j3, HIGH);
    digitalWrite(j4, LOW);
    digitalWrite(j5, LOW);
    digitalWrite(j6, LOW);
  }

  //    mulai
  /*
  for(i=0; i < sizeof(modbus_array); i++){
    
    Serial.print("array");
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(modbus_array[i]);
    Serial.print(" ");
  }
  */
  
  int i;

  for (i = 100; i < 132; ++i)
  {
    Serial.print("   array = ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(modbus_array[i]);
  }
  
  int scheduleAddres ;
  for (scheduleAddres = 100; scheduleAddres < 131; scheduleAddres++){
    
  }
  Serial.println(" ");

}
