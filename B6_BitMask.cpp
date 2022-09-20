#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum{
    GPIO_PIN_0 = 1,
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2,
    GPIO_PIN_3 = 1 << 3,
    GPIO_PIN_4 = 1 << 4,
    GPIO_PIN_5 = 1 << 5,
    GPIO_PIN_6 = 1 << 6,
    GPIO_PIN_7 = 1 << 7
}GPIO_PIN;

typedef enum{
    LOW = 0,
    HIGH = 1,
}STATUS;


uint8_t PORTA = 0b00000000 ;

void digitalWrite(GPIO_PIN PIN, STATUS STATUS ){
    if (STATUS == 1){
        PORTA = PORTA | PIN;
    }
    if (STATUS == 0){
        PORTA = ~ PIN & PORTA;
    }
    
}

void delay(int time)
{
clock_t e;
e = clock() + time * CLOCKS_PER_SEC;
while(clock() < e){}
}

void blink_led(GPIO_PIN PIN, int delay_time){
    PORTA = PORTA | PIN;
    delay(delay_time);
    PORTA = ~ PIN & PORTA;
    delay(delay_time);
}


int main(int argc, char const *argv[])
{
    digitalWrite(GPIO_PIN_5,HIGH);
    printf("Trang thai PORTA: %p", PORTA );
    blink_led(GPIO_PIN_2, 2);
    return 0;
}