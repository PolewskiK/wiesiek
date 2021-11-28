#define F_CPU 16000000L

#include<avr/io.h>
#include<util/delay.h>

#define set(byte, bitNumber) (byte|=(1<<bitNumber))
#define reset(byte, bitNumber) (byte&=~(1<<bitNumber))
#define toggle(byte, bitNumber) (byte^=(1<<bitNumber))
#define check(byte, bitNumber) (byte&(1<<bitNumber)&&1)


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
    DDRC |=1<<PC3;
    DDRC |=1<<PC4;
    DDRC |=1<<PC5;
    while (1)
    {
        reset(PORTC, PC5);
        set(PORTC, PC3);
        sleep(200);
        reset(PORTC, PC3);
        set(PORTC, PC4);
        sleep(200);
        reset(PORTC, PC4);
        set(PORTC, PC5);
        sleep(200);
    }   
}
