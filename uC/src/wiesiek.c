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
    DDRC |=1<<PC2;
    while (1)
    {
        set(PORTC, PC2);
        sleep(200);
        reset(PORTC, PC2);
    }
}
