#define F_CPU 16000000L

#include<avr/io.h>
#include<util/delay.h>
 
#define set(byte, bitNumber) (byte|=(1<<bitNumber))
#define reset(byte, bitNumber) (byte&=~(1<<bitNumber))
#define toggle(byte, bitNumber) (byte^=(1<<bitNumber))
#define check(byte, bitNumber) (byte&(1<<bitNumber)&&1)
#define greenLed PC3
#define redLed PC4
#define blueLed PC5
#define rightForward PA7
#define leftForward PA5
#define rightBackward PA6
#define leftBackward PA4
#define leftPWM OCR0
#define rightPWM OCR2

void proceedMotorsState();
void updateLeftMotorSpeed(const int8_t);
void updateRightMotorSpeed(const int8_t);
void sleep(uint16_t);
void init();

