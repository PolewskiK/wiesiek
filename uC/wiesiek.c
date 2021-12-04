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
        leftPWM = (leftMotorCurrentSpeed * 2) + leftMotorOffset;
    }
    else
    {
        leftPWM = (leftMotorCurrentSpeed * (-2)) + leftMotorOffset;
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
        rightPWM = (rightMotorCurrentSpeed * 2) + rightMotorOffset;
    }
    else
    {
        rightPWM = (rightMotorCurrentSpeed* (-2)) + rightMotorOffset;
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
    sleep(500);
}

void sleep(uint16_t ms)
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
        sleep(500);
        reset(PORTC, greenLed);
        set(PORTC, redLed);
        sleep(500);
        reset(PORTC, redLed);
        set(PORTC, blueLed);
        sleep(500);
        proceedMotorsState();
    }   
}
