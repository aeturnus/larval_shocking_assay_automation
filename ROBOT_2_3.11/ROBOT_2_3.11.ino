// ******LARVAL LEARNING ASSAY ROBOT********//
// Sarwar Khan and Sean Duffy

#include <Servo.h>
#include "ServoMotor.h"
#include "Constants.h"
#include "Pause.h"

ServoMotor Turntable(REST_PLATE_A);
ServoMotor GAOdor(GA_ODOR_ARM_HIGH);              //Group A = Experimental = trained
ServoMotor GAArm(GA_ARM_HIGH);
ServoMotor GBOdor(GB_ODOR_ARM_HIGH);              //Group B = control
ServoMotor GBArm(GB_ARM_HIGH);  

void setup() {

    pinMode(RELAY_A_PIN,OUTPUT);
    pinMode(RELAY_B_PIN,OUTPUT);
    pinMode(PUMP_PIN,OUTPUT);
    pinMode(SWITCH_1_PIN, INPUT);
    PauseInit(PAUSE_SWITCH_PIN);

    
    digitalWrite(RELAY_A_PIN,HIGH);  //turn off (negative logic)
    digitalWrite(RELAY_B_PIN,HIGH);  //turn off (negative logic)
    digitalWrite(PUMP_PIN,HIGH);     //turn off (negative logic)

    Turntable.Init(TURNTABLE_PIN);
    GAArm.Init(LARVAE_ARM_A_PIN);
    GBArm.Init(LARVAE_ARM_B_PIN); 
    GAOdor.Init(ODOR_ARM_A_PIN);    
    GBOdor.Init(ODOR_ARM_B_PIN);    

}

void loop() {

  //NO MOVING MOTORS ABOVE THIS POINT
  int debounce_count = 0;
  while(debounce_count < DEBOUNCE_COUNT){            //wait for button press to begin
    if(digitalRead(SWITCH_1_PIN)==1){debounce_count +=1;}
    else{debounce_count = 0;}  
  }


   //testing
   while(1){
        digitalWrite(RELAY_A_PIN,LOW);      //turn relay on
        delay(15000);
        digitalWrite(PUMP_PIN, HIGH);
        delay(15000);
        digitalWrite(PUMP_PIN, HIGH);
        delay(15000);
        digitalWrite(RELAY_A_PIN,HIGH);      //turn relay on
         delay(15000);
   }
//
//  while(1){
     GAArm.Move(GA_ARM_LOW, 50);
     GAOdor.Move(GA_ODOR_ARM_LOW, 50);
     GAOdor.Move(GA_ODOR_ARM_HIGH, 50);
     GAArm.Move(GA_ARM_HIGH, 50);

     GBArm.Move(GB_ARM_LOW, 50);
     GBOdor.Move(GB_ODOR_ARM_LOW-20, 100);
     GBOdor.Move(GB_ODOR_ARM_HIGH, 50);
     GBArm.Move(GB_ARM_HIGH, 50);

    Turntable.Move(REST_PLATE_A, 40);
     delay(3*1000);
    Turntable.Move(WASH_PLATE_A, 40);  
     delay(3*1000);
    Turntable.Move(DRY_PLATE, 40);  
     delay(3*1000);
    Turntable.Move(VOID_PLATE, 40);
     delay(3*1000);
    Turntable.Move(ODOR_SHOCK_PLATE_A, 40); 
     delay(10*1000); 
    Turntable.Move(REST_PLATE_B, 40); 
     delay(3*1000); 
    Turntable.Move(WASH_PLATE_B, 40);  
     delay(3*1000);
    Turntable.Move(DRY_PLATE_B, 40);  
     delay(3*1000);
    Turntable.Move(ODOR_PLATE_B, 40);  
     delay(3*1000);
    Turntable.Move(SHOCK_PLATE_B, 40);  
    while(1){}
   //end testing

  GAOdor.Move(GA_ODOR_ARM_HIGH, 50);
  GBOdor.Move(GB_ODOR_ARM_HIGH, 50);
  GAArm.Move(GA_ARM_HIGH, 50);            //Pick up both arms from Ringer's
  GBArm.Move(GB_ARM_HIGH, 50);            //control arm will stay up through the trainedarm's cycle
  Turntable.Move(WASH_PLATE_A, 40);

  for(int i=1; i<=(3*NUMBER_OF_ITERATIONS); i+=1){    
      //for experimental
      if(i%3 == 1){  
        Turntable.Move(WASH_PLATE_A, 40);  //bring to position 1 (may not be necessary)
        if(i == 1){    //Drop arms into Ringer's
          GAArm.Move(GA_ARM_LOW, 50);
          GBArm.Move(GB_ARM_LOW, 50);
          delay(5000);      
        }

        GAArm.Move(GA_ARM_HIGH, 50);            //Pick up both arms from Ringer's
        GBArm.Move(GB_ARM_HIGH, 50);            //control arm will stay up through the trainedarm's cycle

        //*****TRAINED GROUP MOVEMENT PROTOCOL*****

        Turntable.Move(WASH_PLATE_A, 40);      // Move to wash plate 
        delay(2000);
        GAArm.Move(GA_ARM_LOW, 50);            // Drop the arm 
        delay(1000);
        //Turntable.Shake(25, 35, 4, 1000);      //Sloshing the transfer chamber
        
        delay(1000);
        GAArm.Move(GA_ARM_HIGH, 50);          //Pick up arm
        Turntable.Move(DRY_PLATE, 40);        // Move to dry plate 
        GAArm.Move(GA_ARM_LOW, 50);           // Drop the arm
        delay(3000);  
        GAArm.Move(GA_ARM_HIGH, 50);          //Pick up arm   
        Turntable.Move(ODOR_SHOCK_PLATE_A, 40);       // Move to odor/shock plate 
        GAArm.Move(GA_ARM_LOW, 50);                  // Drop the arm

        //SHOCK//
        GAOdor.Move(GA_ODOR_ARM_LOW, 50);
//        digitalWrite(PUMP_PIN, LOW);
//        delay(15000);
//        digitalWrite(RELAY_A_PIN,LOW);      //turn relay on
//        digitalWrite(LED_PIN, HIGH);      //Probably should turn on a light when shocking is ocurring for safety
//        delay(15000);
//        digitalWrite(PUMP_PIN, HIGH);
        GAOdor.Move(GA_ODOR_ARM_HIGH, 50);
        //delay(15000);
        //digitalWrite(RELAY_A_PIN,HIGH);     //turn relay off
        //digitalWrite(LED_PIN, LOW);
 
        GAArm.Move(GA_ARM_HIGH, 50);        //Pick up arm  
        Turntable.Move(WASH_PLATE_A, 50);   // Return to wash plate
        GAArm.Move(GA_ARM_LOW, 50);         // Drop the arm 
        //Turntable.Shake(25, 35, 4, 100);    // Slosh
        GAArm.Move(GA_ARM_HIGH, 50);        //Pick up arm
        Turntable.Move(DRY_PLATE, 40);      //Move to dry plate
        GAArm.Move(GA_ARM_LOW, 50);         //Drop  arm
        delay(3000);                        //Allow to Dry
        GAArm.Move(GA_ARM_HIGH, 50);        //Pick up arm
        Turntable.Move(REST_PLATE_A, 40);      // Return to rest Plate (Ringer's)
        GAArm.Move(GA_ARM_LOW, 50);         //Drop  arms
        GBArm.Move(GB_ARM_LOW, 50);
        delay(5000);
                                                                                                                
      }else if(i%3 == 2){// end of the trained group if-statement
        Turntable.Write(REST_PLATE_A);
        GAArm.Move(GA_ARM_HIGH, 50);                   //Pick up arm
        GBArm.Move(GB_ARM_HIGH, 50);                   //trained arm will stay up through the controlarm's cycle

        //*****ControlODOR GROUP MOVEMENT PROTOCOL******
        Turntable.Move(WASH_PLATE_A, 40);              // Move to wash plate
        delay(2000);
        GBArm.Move(GB_ARM_LOW, 50);                            // Drop the controlarm
        delay(1000);
        Turntable.Shake(WASH_PLATE_A-5, WASH_PLATE_A+5, 4, 100);               // Sloshing the transfer chamber
        delay(1000);
        GBArm.Move(GB_ARM_HIGH, 50);                   // Pick up arm
        Turntable.Move(DRY_PLATE, 40);                 // Move to dry plate
        GBArm.Move(GB_ARM_LOW, 50);                    // Drop the arm   
        delay(3000);  
        GBArm.Move(GB_ARM_HIGH, 50);                   // Pick up arm
 
        Turntable.Move(ODOR_PLATE_B, 40);              // Move to odor plate
        GBArm.Move(GB_ARM_LOW, 50);                    // Drop the arm

        //ODOR EXPOSURE
        GBOdor.Move(GB_ODOR_ARM_LOW, 50);
        //digitalWrite(PUMP_PIN, LOW);
        delay(30000);
        //digitalWrite(PUMP_PIN, HIGH);
        GBOdor.Move(GB_ODOR_ARM_LOW, 50);

        GBArm.Move(GB_ARM_HIGH, 50);                   // Pick up arm
        Turntable.Move(WASH_PLATE_A, 40);              // Return to wash plate
        GBArm.Move(GB_ARM_LOW, 50);                    // Drop the arm
        Turntable.Shake(WASH_PLATE_A+5, WASH_PLATE_A-5, 4, 100);               // Slosh
        GBArm.Move(GB_ARM_HIGH, 50);                   // Pick up arm
        Turntable.Move(DRY_PLATE, 40);                 // Move to dry plate
        GBArm.Move(GB_ARM_LOW, 50);                    // Drop  arm
        delay(3000);
        GBArm.Move(GB_ARM_HIGH, 50);                   // Pick up arm
        Turntable.Move(REST_PLATE_A, 40);                 // Return to rest Plate
        GAArm.Move(GA_ARM_LOW, 50);                    // Drop  arms
        GBArm.Move(GB_ARM_LOW, 50);                    
                                                       
        delay(60000*4);
                                                       
       }else if(i%3 == 0){         
        Turntable.Write(REST_PLATE_A);                    //
        GAArm.Move(GA_ARM_HIGH, 50);                   // Pick up arm
        GBArm.Move(GB_ARM_HIGH, 50);                   // trained arm will stay up through the controlarm's cycle

         //*****ControlSHOCK GROUP MOVEMENT PROTOCOL******
 
         Turntable.Move(WASH_PLATE_A, 40);            // Move to wash plate
         delay(2000);
         GBArm.Move(GB_ARM_LOW, 50);                  // Drop the controlarm
         delay(1000);
         Turntable.Shake(WASH_PLATE_A+5, WASH_PLATE_A-5, 4, 100);             //Sloshing the transfer chamber
         delay(1000);
         GBArm.Move(GB_ARM_HIGH, 50);                 //Pick up arm
         Turntable.Move(DRY_PLATE, 40);               // Move to dry plate 
         GBArm.Move(GB_ARM_LOW, 50);                  // Drop the arm 
         delay(3000);  
         GBArm.Move(GB_ARM_HIGH, 50);                 // Pick up arm
         Turntable.Move(SHOCK_PLATE_B, 40);           // Move to shock plate
         GBArm.Move(GB_ARM_LOW, 50);                  // Drop the arm 

         //digitalWrite(RELAY_B_PIN, LOW);              // SHOCK
         //digitalWrite(LED_PIN, HIGH);
         delay(30000);
         //digitalWrite(RELAY_B_PIN, HIGH);             // Stop Shock
         //digitalWrite(LED_PIN, LOW);

         GBArm.Move(GB_ARM_HIGH, 50);                 //Pick up arm
         Turntable.Move(WASH_PLATE_A, 40);            // Return to wash plate
         GBArm.Move(GB_ARM_LOW, 50);                  // Drop the arm
         Turntable.Shake(WASH_PLATE_A+5, WASH_PLATE_A-5, 4, 100);             // Slosh
         GBArm.Move(GB_ARM_HIGH, 50);                 // Pick up arm
         Turntable.Move(DRY_PLATE, 40);               // Move to dry plate 
         GBArm.Move(GB_ARM_LOW, 50);                  // Drop  arm
         delay(3000);
         GBArm.Move(GB_ARM_HIGH, 50);                 // Pick up arm
         Turntable.Move(REST_PLATE_A, 40);               // Return to rest Plate
         GAArm.Move(GA_ARM_LOW, 50);                  // Drop  arm
         GBArm.Move(GB_ARM_LOW, 50);

         delay(60000*2);
      }
  }  
}
