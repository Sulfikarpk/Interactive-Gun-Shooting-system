#define DEBUG 0
#define CALLIBRATION_ENABLE 0

#define BUTTON_PIN1 23// gun1 Switch_pin
#define BUTTON_PIN2 22//gun2 Switch_pin

#define X1_TARGET_MIN 0
#define X1_TARGET_MAX 100
#define Y1_TARGET_MIN 0
#define Y1_TARGET_MAX 100

#define X2_TARGET_MIN 0
#define X2_TARGET_MAX 100
#define Y2_TARGET_MIN 0
#define Y2_TARGET_MAX 100


#define BUTTON1_PRESSED !digitalRead(BUTTON_PIN1)
#define BUTTON2_PRESSED !digitalRead(BUTTON_PIN2)

#include <SCServo.h>
#include "EEPROM.h"
SMS_STS sc ;

bool already_trigger_informed1 = 0;
bool already_trigger_informed2 = 0;

int16_t x1_min = 0;
int16_t x1_max = 0;
int16_t y1_min = 0;
uint16_t y1_max = 0;

int16_t x2_min = 0;
int16_t x2_max = 0;
int16_t y2_min = 0;
uint16_t y2_max = 0;

void scservo_setup()
{
  if(DEBUG) { Serial.println("DEBUG Mode ON"); }
  sc.pSerial = &Serial2;
}

int16_t read_position1()
{
  return sc.ReadPos(1);
}
int16_t read_position2()
{
  return sc.ReadPos(2);
}

int16_t read_position3()
{
  return sc.ReadPos(3);
}

int16_t read_position4()
{
  return sc.ReadPos(4);
}

void self_callibration_handler()
{
  //gun1
  if( ! CALLIBRATION_ENABLE ) { return; }
  Serial.println("Callibration mode \n \n Please move the gun to LEFT edge of the screen, Then press the Trigger button");
  while( ! BUTTON1_PRESSED ) { yield();  Serial.println("Callibration mode \n \n Please move the gun1 to LEFT edge of the screen, Then LONG PRESS the Trigger button"); delay (500);}
  x1_min = read_position1();
  Serial.println( "\n\n\n\nLeft side callibrated \n \n Please move the gun1 to RIGHT edge of the screen, Then press the Trigger button" );
  while(  BUTTON1_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON1_PRESSED ) { yield(); }
  x1_max = read_position1();
  Serial.println( "\n\n\n\nRight side callibrated \n \n Please move the gun1 to TOP edge of the screen, Then press the Trigger button" );
  while(  BUTTON1_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON1_PRESSED ) { yield(); }
  y1_min = read_position2();
  Serial.println( "\n\n\n\nTop side callibrated \n \n Please move the gun1 to BOTTOM edge of the screen, Then press the Trigger button" );
  while(  BUTTON1_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON1_PRESSED ) { yield(); }
  y1_max = read_position2();
  Serial.println( "\n\n\n\nBottom side callibrated \n \n gun1 Callibrarion done... \n New encoder_values are \n X1 min : " + String(x1_min) + ",   X1 max : " + String (x1_max) + ",   Y1 min : " + String (y1_min) + ",   Y1 max : " + String (y1_max)  );
//gun2
   while( ! BUTTON2_PRESSED ) { yield();  Serial.println("Callibration mode \n \n Please move the gun2 to LEFT edge of the screen, Then LONG PRESS the Trigger button"); delay (500);}
  x2_min = read_position3();
  Serial.println( "\n\n\n\nLeft side callibrated \n \n Please move the gun2 to RIGHT edge of the screen, Then press the Trigger button" );
  while(  BUTTON2_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON2_PRESSED ) { yield(); }
  x2_max = read_position3();
  Serial.println( "\n\n\n\nRight side callibrated \n \n Please move the gun2 to TOP edge of the screen, Then press the Trigger button" );
  while(  BUTTON2_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON2_PRESSED ) { yield(); }
  y2_min = read_position4();
  Serial.println( "\n\n\n\nTop side callibrated \n \n Please move the gun2 to BOTTOM edge of the screen, Then press the Trigger button" );
  while(  BUTTON2_PRESSED ) { yield(); }
  delay(1000);
  while( ! BUTTON2_PRESSED ) { yield(); }
  y2_max = read_position4();

  Serial.println( "\n\n\n\nBottom side callibrated \n \n gun2 Callibrarion done... \n New encoder_values are \n X2 min : " + String(x2_min) + ",   X2 max : " + String (x2_max) + ",   Y2 min : " + String (y2_min) + ",   Y2 max : " + String (y2_max)  );
  EEPROM.put(0, x1_min);
  EEPROM.put(2, x1_max);
  EEPROM.put(4, y1_min);
  EEPROM.put(6, y1_max);

  EEPROM.put(8,  x2_min);
  EEPROM.put(10, x2_max);
  EEPROM.put(12, y2_min);
  EEPROM.put(14, y2_max);
  EEPROM.commit();

}
void EEPROM_setup()
{
  EEPROM.get(0, x1_min);
  EEPROM.get(2, x1_max);
  EEPROM.get(4, y1_min);
  EEPROM.get(6, y1_max);

  EEPROM.get(8, x2_min);
  EEPROM.get(10, x2_max);
  EEPROM.get(12, y2_min);
  EEPROM.get(14, y2_max);

  if(x1_min > 4095) { Serial.println("Callibration value Error,  Please re-callibrate to use..."); delay(2000); ESP.restart(); }
}
// void post()
// {
//   if( read_position1() >= 0 ) { return; }
//   Serial.println( " X axis sensor failed / not connected " );
//   if( read_position2() >= 0 ) { return ; }
//   Serial.println( " Y axis sensor failed / not connected \n Please check the wiring manually... " );
//   delay(2000);
//   ESP.restart();
// }
void button_trigger_handler()
{
  if( BUTTON1_PRESSED )
  {
    if( !already_trigger_informed1 ) { Serial.println("*1=A#"); already_trigger_informed1 = 1; } 
  }
  else { already_trigger_informed1 = 0; }

  if( BUTTON2_PRESSED )
  {
    if( !already_trigger_informed2 ) { Serial.println("*2=B#"); already_trigger_informed2 = 1; } 
  }
  else { already_trigger_informed2 = 0; }

}
void gun_pointer_handler()
{
  int16_t x1 = map( read_position1(), x1_min, x1_max, X1_TARGET_MIN, X1_TARGET_MAX );
  if( x1 > X1_TARGET_MAX ) { x1 = X1_TARGET_MAX; }
  if( x1 < X1_TARGET_MIN ) { x1 = X1_TARGET_MIN; }
  int16_t y1 = map( read_position2(), y1_min, y1_max, Y1_TARGET_MIN, Y1_TARGET_MAX );
  if( y1 > Y1_TARGET_MAX ) { y1 = Y1_TARGET_MAX; }
  if( y1 < Y1_TARGET_MIN ) { y1 = Y1_TARGET_MIN; }
  Serial.println("*1=" + String(x1) + "," + String(y1) + "#" );

  int16_t x2 = map( read_position3(), x2_min, x2_max, X2_TARGET_MIN, X2_TARGET_MAX );
  if( x2 > X2_TARGET_MAX ) { x2 = X2_TARGET_MAX; }
  if( x2 < X2_TARGET_MIN ) { x2 = X2_TARGET_MIN; }
  int16_t y2 = map( read_position4(), y2_min, y2_max, Y2_TARGET_MIN, Y2_TARGET_MAX );
  if( y2 > Y2_TARGET_MAX ) { y2 = Y2_TARGET_MAX;}
  if( y2 < Y2_TARGET_MIN ) { y2 = Y2_TARGET_MIN; }
  Serial.println("*2=" + String(x2) + "," + String(y2) + "#" );
}
void setup()  
{
  pinMode(BUTTON_PIN1,INPUT_PULLUP);
  pinMode(BUTTON_PIN2,INPUT_PULLUP);
  Serial.begin(9600);
  Serial2.begin(1000000,SERIAL_8N1,16,17);
  EEPROM.begin(512);
  scservo_setup();
  delay(100);
  //post();
  self_callibration_handler();
  EEPROM_setup();
}
void loop() 
{
  button_trigger_handler();
  gun_pointer_handler();
  delay(19);
}
