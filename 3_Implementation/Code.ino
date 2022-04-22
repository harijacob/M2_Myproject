//#include <LiquidCrystal.h>
//LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //rs,en,d4,d5,d6,d7
#include "rfid.h"
#include "lcd.h"
void reader (void);
void ir_state(void);
int ir, ir2, ir3;

void setup()
{
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  //lcd.clear();
  pinMode(49, INPUT);
  pinMode(51, INPUT);
  pinMode(53, INPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("CAR PARKING");
  delay(500);

}
void loop()
{
  reader();
  delay(1000);
}//=========================================================//
void reader (void) {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("PLACE CARD");
  do {
    rfid();
    ir_state();
  }
  while (rfid() == 0);
  if (rfid() == 1)
  {
    rfidno = 0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("CAR1");
  }
  if (rfid() == 2)
  {
    rfidno = 0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("CAR2");
  }
  if (rfid() == 3)
  {
    rfidno = 0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("CAR3");
  }
}
void ir_state(void)
{
  ir = digitalRead(49);
  ir2 = digitalRead(51);
  ir3 = digitalRead(53) ;
  lcd.setCursor(0, 0);
  lcd.print("S1:");
  lcd.setCursor(6, 0);
  lcd.print("S2:");
  lcd.setCursor(12, 0);
  lcd.print("S3:");
  delay(500);
  if (ir == 0)
  {
    lcd.setCursor(3, 0);
    lcd.print("1");
    digitalWrite(30, HIGH);
    digitalWrite(31, LOW);
  }
  else
  {
    lcd.setCursor(3, 0);
    lcd.print("0");
    digitalWrite(31, HIGH);
    digitalWrite(30, LOW);
  }
  //=====================================================//
  if (ir2 == 0)
  {
    lcd.setCursor(9, 0);
    lcd. print("1");
    digitalWrite(32, HIGH);
    digitalWrite(33, LOW);
  }
  else
  {
    lcd.setCursor(9, 0);
    lcd.print("0");
    digitalWrite(33, HIGH);
    digitalWrite(32, LOW);
  }
  //======================================================//
  if (ir3 == 0)
  {
    lcd.setCursor(15, 0);
    lcd. print("1");
    digitalWrite(34, HIGH);
    digitalWrite(35, LOW);
  }
  else
  {
    lcd.setCursor(15, 0);
    lcd.print("0");
    digitalWrite(35, HIGH);
    digitalWrite(34, LOW);
  }
}
