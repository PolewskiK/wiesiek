#include "wiesiek.h"

int8_t leftMotorCurrentSpeed, rightMotorCurrentSpeed, leftMotorSetSpeed, rightMotorSetSpeed;

void proceedMotorsState()
{
    if (leftMotorCurrentSpeed != leftMotorSetSpeed) 
    {
        updateLeftMotorSpeed(leftMotorSetSpeed);
    }
    if (rightMotorCurrentSpeed != rightMotorSetSpeed)
    {
        updateRightMotorSpeed(rightMotorSetSpeed);
    }
}

void updateLeftMotorSpeed(const int8_t setSpeed)
{
    if (setSpeed == 0)
    {
        reset(PORTA, leftForward);
        reset(PORTA, leftBackward);
    }
    else if (leftMotorCurrentSpeed >= 0 && setSpeed < 0)
    {
        reset(PORTA, leftForward);
        set(PORTA, leftBackward);
    }
    else if (leftMotorCurrentSpeed <=0 && setSpeed > 0)
    {
        reset(PORTA, leftBackward);
        set(PORTA, leftForward);
    }
    
    leftMotorCurrentSpeed = setSpeed;
    if (leftMotorCurrentSpeed >= 0)
    {
        leftPWM = leftMotorCurrentSpeed;
    }
    else
    {
        leftPWM = (leftMotorCurrentSpeed*(-1));
    }
}

void updateRightMotorSpeed(const int8_t setSpeed)
{
    if (setSpeed == 0)
    {
        reset(PORTA, rightForward);
        reset(PORTA, rightBackward);
    }
    else if (rightMotorCurrentSpeed >= 0 && setSpeed < 0)
    {
        reset(PORTA, rightForward);
        set(PORTA, rightBackward);
    }
    else if (rightMotorCurrentSpeed <= 0 && setSpeed > 0)
    {
        reset(PORTA, rightBackward);
        set(PORTA, rightForward);
    }

    rightMotorCurrentSpeed = setSpeed;
    if (rightMotorCurrentSpeed >= 0)
    {
        rightPWM = rightMotorCurrentSpeed;
    }
    else
    {
        rightPWM = (rightMotorCurrentSpeed*(-1));
    }
}

void init()
{
    DDRA = 0xFF;
    DDRB = 0xF8;
    DDRC = 0xFD;
    DDRE = 0x10;
    DDRG = 0xFF;
    TCCR0 = 0x69;
    TCCR2 = 0x69;
}

void sleep(uint8_t ms)
{
    while(ms)
    {
        _delay_ms(1);
        ms--;
    }
}

int main(void)
{
    init();
    while (1)
    {
        reset(PORTC, blueLed);
        set(PORTC, greenLed);
        sleep(200);
        reset(PORTC, greenLed);
        set(PORTC, redLed);
        sleep(200);
        reset(PORTC, redLed);
        set(PORTC, blueLed);
        sleep(200);
        proceedMotorsState();
    }   
}
