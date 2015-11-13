#include <Arduino.h>
#include "Constants.h"
#include "Pause.h"

void PauseInit(int pin){  //initialize edge-triggered interrupts here
  pinMode(pin,INPUT);
  int interrupt_number;
  if(pin == 2){interrupt_number = 0;}
  if(pin == 3){interrupt_number = 1;}
  attachInterrupt(interrupt_number, Pause, RISING);
} 
 
//call this function in the ISR for the edge-triggered interrupt  
//THE SWTICH TO UNPAUSE IS THE START SWITCH, NOT THE PAUSE SWITCH, THIS CAN EASILY BE CHANGED, BUT NEED TO USE detachInterrupt() FIRST (I think)
void Pause(void){
    int debounce_count = 0;  
    digitalWrite(RELAY_A_PIN,HIGH);  //turn off (negative logic) //remember to turn off relays, pumps, etc
    digitalWrite(RELAY_B_PIN,HIGH);  //turn off (negative logic)
    digitalWrite(PUMP_PIN,HIGH);     //turn off (negative logic)
        
    //switch is originally high                                 check this, remember it is not the switch that got you here
    while(debounce_count < DEBOUNCE_COUNT){
      if(digitalRead(SWITCH_1_PIN) == LOW){debounce_count += 1;}
      if(digitalRead(SWITCH_1_PIN) == HIGH){debounce_count = 0;}
    }
    //switch is now low (has been unpressed)
    
    debounce_count = 0;
    while(debounce_count < DEBOUNCE_COUNT){
      if(digitalRead(SWITCH_1_PIN) == HIGH){debounce_count += 1;}
      if(digitalRead(SWITCH_1_PIN) == LOW){debounce_count = 0;}
    }
    //switch is now high (has been pressed again)->unpause
    
    //wait for swtich to be unpressed so it does not interrupt again
    debounce_count = 0;
    while(debounce_count < DEBOUNCE_COUNT){
      if(digitalRead(SWITCH_1_PIN) == LOW){debounce_count += 1;}
      if(digitalRead(SWITCH_1_PIN) == HIGH){debounce_count = 0;}
    }
    delayMicroseconds(1000);
} 
