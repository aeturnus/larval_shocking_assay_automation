#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Servo.h>
#include <Arduino.h>

class ServoMotor{
  public:
    ServoMotor(short);
    ~ServoMotor();
    void Shake(int, int, int, int);
    void Move(int, int);
    void Init(int);
    void Set(int);
    void Write(int);
  private:
    Servo Motor;
    short angle;
};

#endif
