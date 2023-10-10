
#define LED_PRESSED_BUTTON 2
#define             RED_L1 3
#define          YELLOW_L2 4
#define           GREEN_L3 5
#define             RED_L4 6
#define          YELLOW_L5 7
#define           GREEN_L6 8

#define clock_speed 3000

#include "OneButton.h"
#include <TimerOne.h>

OneButton button_A(14, true, false);         
OneButton button_B(15, true, false);   
OneButton button_C(16, true, false);  

unsigned int new_Event = 0;
unsigned int myTime = 0;

void setup() {

  pinMode(LED_PRESSED_BUTTON, OUTPUT);
  pinMode(RED_L1, OUTPUT);
  pinMode(YELLOW_L2, OUTPUT);
  pinMode(GREEN_L3, OUTPUT);
  pinMode(RED_L4, OUTPUT);
  pinMode(YELLOW_L5, OUTPUT);
  pinMode(GREEN_L6, OUTPUT);

  button_A.attachLongPressStart(click1);
  button_B.attachLongPressStart(click2);
  button_C.attachLongPressStart(click3);

  Timer1.attachInterrupt(timerIsr);
  Timer1.initialize(5000); 

  Serial.begin(115200);

}

void timerIsr() {

  button_A.tick();
  button_B.tick();
  button_C.tick();
      
}

void loop() {
  
 //digitalWrite(RED_L1, HIGH); delay(clock_speed); digitalWrite(RED_L1, LOW);
 //digitalWrite(YELLOW_L2, HIGH); delay(clock_speed); digitalWrite(YELLOW_L2, LOW);
 //digitalWrite(GREEN_L3, HIGH); delay(clock_speed); digitalWrite(GREEN_L3, LOW);

 do {
     digitalWrite(RED_L1, HIGH);
     digitalWrite(RED_L4, HIGH);
    } while(new_Event == 0);

 delay(3000);   

 digitalWrite(LED_PRESSED_BUTTON, LOW);

 digitalWrite(RED_L1, LOW); digitalWrite(RED_L4, LOW);
 
 digitalWrite(YELLOW_L2, HIGH); digitalWrite(YELLOW_L5, HIGH); delay(2000); 
 digitalWrite(YELLOW_L2, LOW); digitalWrite(YELLOW_L5, LOW);
 
 digitalWrite(GREEN_L3, HIGH); digitalWrite(GREEN_L6, HIGH); delay(myTime); 
 digitalWrite(GREEN_L3, LOW);  digitalWrite(GREEN_L6, LOW);
 new_Event = 0;

}

void click1() {
                new_Event = 1; 
                myTime = 3000;
                digitalWrite(LED_PRESSED_BUTTON, HIGH);
              }
              

void click2() { 
                new_Event = 1;
                myTime = 5000;
                digitalWrite(LED_PRESSED_BUTTON, HIGH);
              }

void click3() { 
                new_Event = 1;
                myTime = 15000;
                digitalWrite(LED_PRESSED_BUTTON, HIGH);
              }              
