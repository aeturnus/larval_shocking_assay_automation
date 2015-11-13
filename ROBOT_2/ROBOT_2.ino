/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 #include <Servo.h>
 
// Pin 13 has an LED connected on most Arduino boards.
// ROBOT 2*****//

//Initialize the  LEDs
int switch1 = 13;




Servo Turntable;
Servo GAOdor;
Servo GAArm;
Servo GBOdor;
Servo GBArm;

int angleTurntable = 0;
int angleGAOdor = 0;
int angleGAArm  = 0;
int angleGBOdor = 0;
int angleGBArm = 0; 


int foo = 0;
int soo = 0;
int moo = 0;
int reset = 0;
int counter = 1;

int relaygroupA = 6;
int relaygroupB = 7;
int pump = 8;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
 // pinMode(ledGREEN1, OUTPUT);     
      
   
   
   // Relay 
   pinMode(relaygroupA,OUTPUT);
      pinMode(relaygroupB,OUTPUT);
      pinMode(pump,OUTPUT);

//Servo Intitialize
   Turntable.attach(8);   
   GAOdor.attach(0);
   GAArm.attach(1);
   GBOdor.attach(3);
   GBArm.attach(2);
   
// Switch   
    pinMode(switch1, INPUT);
    
}

// the loop routine runs over and over again forever:
void loop() {
   
Turntable.write(1);

    
  digitalWrite(relaygroupA,HIGH);
  digitalWrite(relaygroupB,HIGH);
  digitalWrite(pump,HIGH); 
  
 
    if(digitalRead(switch1) == HIGH){
      foo = 1;
    }
   else if(digitalRead(switch1) == LOW){
     foo= 0;
   }
   
      if(counter>1 && counter<13){
      foo =1;
       digitalWrite(ledRED1,HIGH);
       delay(3000);
       digitalWrite(ledRED1,LOW);
}

      
      switch (foo) {
      case 1:
      
      
    digitalWrite(ledGREEN1, HIGH);    
    delay(1000);               // wait for a second
   digitalWrite(ledGREEN1, LOW);    // turn the LED off by making the voltage LOW
   delay(1000);               // wait for a second
    

if(counter==1 || counter ==4 ||counter ==7 || counter==10){
//Center Servo
  Turntable.write(1);
  digitalWrite(ledGREEN1, HIGH); 

if(counter==1){
// Drop the arm 

armtrained.write(170);

   for(angle1=170; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 

  
  
  armcontrol.write(120);

   for(angle2=120; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

  delay(3000);
  
}
  
  //Pick up arm
  
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  //control arm will stay up through the trainedarm's cycle
   for(angle2=10; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
//*****TRAINED GROUP MOVEMENT PROTOCOL******////
 
     
 //**** 1ST PAUSE/RESET CYCLE ***** //    
   
        
        //***Pause Button check***
  myPauseFunction();
//************//

digitalWrite(ledGREEN2,HIGH);
// Move to wash plate 
  for(angle=angle; angle <30; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }

delay(2000);



// Drop the arm 
   for(angle1=170; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 

 
  
delay(1000);
//Sloshing the transfer chamber
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);

delay(1000);

 //Pick up arm
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 


//***** 2ND PAUSE/RESET CYCLE ******
   
        
        //***Pause Button check***
 myPauseFunction();

//************//

digitalWrite(ledGREEN2,LOW);


// Move to dry plate 
digitalWrite(ledGREEN3,HIGH);

  for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
  
// Drop the arm 


   for(angle1=170; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  
delay(3000);  
  
  //Pick up arm
  
   for(angle1=angle1; angle1<180; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  }  
 
 
 
 //***** 3RD PAUSE/RESET CYCLE ******

          //***Pause Button check***
 myPauseFunction();
 
//************//
 
 
 
 
   
 // Move to odor/shock plate 
 digitalWrite(ledRED1,HIGH);
   for(angle=angle; angle<127; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
 
 // Drop the arm 
   for(angle1=angle1; angle1>95; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
 //SHOCK//
 //SHOCK//
 //SHOCK//
 delay(15000);
 digitalWrite(relaytrained,LOW);
  delay(30000);
  digitalWrite(relaytrained,HIGH);
  
  //Pick up arm
  
   for(angle1=angle1; angle1<180; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 

 
 
 //***** 4TH PAUSE/RESET CYCLE ******
    
        
         //***Pause Button check***
 myPauseFunction();

 
        
        digitalWrite(ledRED1,LOW);
//************//
 

////************//


// Return to wash plate
digitalWrite(ledGREEN2,HIGH);
 for(angle=angle; angle>30; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  }


 // Drop the arm 
   for(angle1=170; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
 
  
 
// Slosh
Turntable.write(35);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);

 //Pick up arm
  
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 



//***** 6TH PAUSE/RESET CYCLE ******
 myPauseFunction();

//************//

//Move to dry plate
digitalWrite(ledGREEN3,HIGH);
for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
   //Drop  arm
   for(angle1=angle1; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  
  delay(3000);
  
   //Pick up arm
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  
  //***** 7TH PAUSE/RESET CYCLE ******
 myPauseFunction();
        digitalWrite(ledGREEN3,LOW);
//************//
  
 // Return to rest Plate
 digitalWrite(ledGREEN1,HIGH);
 for(angle=angle; angle>=1; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  } 
 
 
  //Drop  arm
   for(angle1=angle1; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
   
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
 digitalWrite(ledGREEN1,LOW);


counter+=1; // THis will count the iteration of the training cycle
foo = 0; // This makes sure the switch case always has to meet the correct conditions
if(counter!=2){
 digitalWrite(ledGREEN1,HIGH);

  delay(60000); 
 digitalWrite(ledGREEN1,LOW);

}
else{
    digitalWrite(ledGREEN2,HIGH);

  delay(5000);
   digitalWrite(ledGREEN2,LOW);

}
break;
}// end of the trained group if-statement



/////*********
//*****
//*******
//******
//Controlodor
else if(counter == 2 || counter == 5 || counter == 8 || counter == 11){
//control odor
//Center Servo
  Turntable.write(1);
  digitalWrite(ledGREEN1, HIGH); 

  //Pick up arm
  //trained arm will stay up through the controlarm's cycle
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  
   for(angle2=10; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
//*****ControlODOR GROUP MOVEMENT PROTOCOL******////
 
     
 //**** 1ST PAUSE/RESET CYCLE ***** //    
        
        //***Pause Button check***
 myPauseFunction();

//************//

digitalWrite(ledGREEN2,HIGH);
// Move to wash plate 
  for(angle=angle; angle <30; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }

delay(2000);

// Drop the controlarm 
   for(angle2=120; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
 
delay(1000);
//Sloshing the transfer chamber
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);

delay(1000);

 //Pick up arm
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 


//***** 2ND PAUSE/RESET CYCLE ******

        //***Pause Button check***
 myPauseFunction();
//************//

digitalWrite(ledGREEN2,LOW);


// Move to dry plate 
digitalWrite(ledGREEN3,HIGH);

  for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
  
// Drop the arm 


   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
delay(3000);  
  
  //Pick up arm
  
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  }  
 
 
 
 //***** 3RD PAUSE/RESET CYCLE ******
        
          //***Pause Button check***
 myPauseFunction();

        digitalWrite(ledGREEN3,LOW);
       
        
        
//************//
 
 // Move to odor plate 
 digitalWrite(ledRED1,HIGH);
   for(angle=angle; angle<108; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
 
 // Drop the arm 
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

//ODOR EXPOSURE
  delay(30000);
  //ODOR EXPOSURE

  //Pick up arm
  
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

 
 
 //***** 4TH PAUSE/RESET CYCLE ******
         //***Pause Button check***
 myPauseFunction();
        digitalWrite(ledRED1,LOW);
 



// Return to wash plate
digitalWrite(ledGREEN2,HIGH);
 for(angle=angle; angle>30; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  }


 // Drop the arm 
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
 
  
 
// Slosh
Turntable.write(35);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);

 //Pick up arm
  
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 



//***** 6TH PAUSE/RESET CYCLE ******
        
          //***Pause Button check***
 myPauseFunction();
        digitalWrite(ledGREEN2,LOW);

//************//

//Move to dry plate
digitalWrite(ledGREEN3,HIGH);
for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
   //Drop  arm
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
  delay(3000);
  
   //Pick up arm
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
  //***** 7TH PAUSE/RESET CYCLE ******

         //***Pause Button check***
  myPauseFunction();
        digitalWrite(ledGREEN3,LOW);
//************//
  
 // Return to rest Plate
 digitalWrite(ledGREEN1,HIGH);
 for(angle=angle; angle>=1; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  } 
 
 
  //Drop  arm
   for(angle1=angle1; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
   
 for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 


counter+=1; // THis will count the iteration of the training cycle
foo = 0; // This makes sure the switch case always has to meet the correct conditions
//myservo.detach(8);   
//   armtrained.detach(5);
//   armcontrol.detach(4);
delay(60000*4);
//myservo.attach(8);   
//   armtrained.attach(5);
//   armcontrol.attach(4);
break;

}

//********************
//********************
//*******************
//********************
//Control SHOCK


else if(counter == 3 || counter == 6 || counter == 9 || counter ==12){
//control shock
//Center Servo
 Turntable.write(1);
  digitalWrite(ledGREEN1, HIGH); 


  
  //Pick up arm
  //trained arm will stay up through the controlarm's cycle
   for(angle1=angle1; angle1<170; angle1+=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
  
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
//*****ControlSHOCK GROUP MOVEMENT PROTOCOL******////
 
     
 //**** 1ST PAUSE/RESET CYCLE ***** //     
        //***Pause Button check***
 myPauseFunction();
//************//

digitalWrite(ledGREEN2,HIGH);
// Move to wash plate 
  for(angle=angle; angle <30; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }

delay(2000);



// Drop the controlarm 
   for(angle2=120; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

 
  
delay(1000);
//Sloshing the transfer chamber
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);
Turntable.write(25);
  delay(100);
Turntable.write(35);
delay(100);

delay(1000);

 //Pick up arm
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 


//***** 2ND PAUSE/RESET CYCLE ******
        
        //***Pause Button check***
  myPauseFunction();
//************//

digitalWrite(ledGREEN2,LOW);


// Move to dry plate 
digitalWrite(ledGREEN3,HIGH);

  for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
  
// Drop the arm 


   for(angle2=120; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
delay(3000);  
  
  //Pick up arm
  
   for(angle2=angle2; angle2<140; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  }  
 
 
 
 //***** 3RD PAUSE/RESET CYCLE ******
        
          //***Pause Button check***
 myPauseFunction(); 
//************//
   
 // Move to shock plate 
 digitalWrite(ledRED1,HIGH);
   for(angle=angle; angle<133; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
 
 // Drop the arm 
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

//SHOCK SHOCKS SHOCK
digitalWrite(relaycontrol, LOW);
  delay(30000);
  digitalWrite(relaycontrol, HIGH);
  //SHOCK SHOCK

  //Pick up arm
  
   for(angle2=angle2; angle2<140; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

 
 
 //***** 4TH PAUSE/RESET CYCLE ******
        
         //***Pause Button check***
 myPauseFunction();
        digitalWrite(ledRED1,LOW);
 
// Return to wash plate
digitalWrite(ledGREEN2,HIGH);
 for(angle=angle; angle>30; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  }


 // Drop the arm 
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

// Slosh
Turntable.write(35);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);
Turntable.write(30);
  delay(100);
Turntable.write(25);
delay(100);

 //Pick up arm
  
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 

//***** 6TH PAUSE/RESET CYCLE ******

          //***Pause Button check***
 myPauseFunction();
        digitalWrite(ledGREEN2,LOW);

//************//

//Move to dry plate
digitalWrite(ledGREEN3,HIGH);
for(angle=angle; angle<60; angle+=1)
  {
      Turntable.write(angle);
      delay(40);
  }
 
   //Drop  arm
   for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
  delay(3000);
  
   //Pick up arm
   for(angle2=angle2; angle2<120; angle2+=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 
  
  //***** 7TH PAUSE/RESET CYCLE ******
         //***Pause Button check***
 myPauseFunction();
        digitalWrite(ledGREEN3,LOW);
//************//
  
 // Return to rest Plate
 digitalWrite(ledGREEN1,HIGH);
 for(angle=angle; angle>=1; angle-=1)
  {
      Turntable.write(angle);
      delay(40);
  } 
 
 
  //Drop  arm
   for(angle1=angle1; angle1>120; angle1-=1)
  {
      armtrained.write(angle1);
      delay(50);
  } 
   
 for(angle2=angle2; angle2>10; angle2-=1)
  {
      armcontrol.write(angle2);
      delay(50);
  } 


counter+=1; // THis will count the iteration of the training cycle
foo = 0; // This makes sure the switch case always has to meet the correct conditions

delay(60000*2);

break;
}
// **IF THE BUTTON is NOT pressed: Do nothing

default:
foo = 0;
break;
    
      } 
   

}





//****PAUSE FUNCTION//
void myPauseFunction(){
  
       //***Pause Button check***
       moo = 0;
      soo = 0; 
while(moo<=3){
  
  if(digitalRead(switch1) == HIGH)
    {
      digitalWrite(ledGREEN1,HIGH);
      delay(3000);
      digitalWrite(ledGREEN1,LOW);
      delay(3000);
      while(soo<1){
      digitalWrite(ledGREEN2,HIGH);
      delay(3000);
      digitalWrite(ledGREEN2,LOW);
      delay(3000);
            if(digitalRead(switch1) == HIGH)
            {
               digitalWrite(ledGREEN3,HIGH);
      delay(3000);
      digitalWrite(ledGREEN3,LOW);
      delay(3000);
              soo=1;
              moo=3;
             
            }
      
                  } 
        
    }
  
   else if(digitalRead(switch1) == LOW)
   {
     moo+=1;
   }
   delay(1000);
  
}
  
}
