#include <stdio.h>
#include <stdlib.h>

enum state {TOFF, TON, BLINK};
enum state current = TOFF;

int input_state = 0;
void (*func)();

void turn_off();
void turn_on();
void blink();

/*************************************************************/

int main(){
    while(1){
        scanf("%d", &input_state);
        if(current == TON){
            func = turn_on;
        }
        if(current == TOFF){
            func = turn_off;
        }
        if(current == BLINK){
            func = blink;
        }
        func();
}
return 0;
}

/*************************************************************/

void turn_off(){
    printf("Device is turned off\n");
    if(input_state){
        current = TON;
    }
}
void turn_on(){
    printf("Device is turned on\n");
    if(input_state){
        current = BLINK;
    }
}
void blink(){
    printf("Blinking\n");
    if(input_state){
        current = TOFF;
    }
}
