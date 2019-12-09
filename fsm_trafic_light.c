#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum color {RED, YELLOW, GREEN};
enum color current_color = RED;

void (*func)();
void red();
void yellow();
void green();
void delay();


int main(){
    while (1){
        if(current_color == GREEN){
            func = green;
            delay(9);
        }
        if(current_color == RED){
            func = red;
            delay(5);
        }
        if(current_color == YELLOW){
            func = yellow;
            delay(9);
        }
        func();
    }

return 0;
}

/*****************************************************/

void red(){
    printf("RED\n");
    current_color = GREEN;
}
void yellow(){
    printf("YELLOW\n");
    current_color = RED;
}
void green(){
    printf("GREEN\n");
    current_color = YELLOW;
}

void delay(unsigned int mseconds){
    clock_t goal = 100000 * mseconds + clock();
    while (goal > clock());
}


