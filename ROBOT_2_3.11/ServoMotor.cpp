#include "ServoMotor.h"

ServoMotor::ServoMotor(short start){
  angle = start;  
}

ServoMotor::~ServoMotor(){}

void ServoMotor::Shake(int position1, int position2, int repititions, int delay_len){
  int i;
  for(i = 0; i<repititions; i += 1){
     Motor.write(position1);
     delay(delay_len);
     Motor.write(position2);   
  } 
}

void ServoMotor::Move(int position2, int delay_len){
  int i;
  if(angle == position2){return;}
  if(angle<position2){                                //up
    for(i = angle; i<position2; i += 1){
       Motor.write(i);
       delay(delay_len);
    }
  }else{                                              //down
    for(i = angle; i>position2; i -= 1){
       Motor.write(i);
       delay(delay_len);
    }    
  }
  angle = position2;
}

void ServoMotor::Init(int pin){
  Motor.attach(pin);
  pinMode(pin, OUTPUT);
}

void ServoMotor::Set(int pos){
  angle = pos;
}

void ServoMotor::Write(int pos){
  Motor.write(pos);
}
