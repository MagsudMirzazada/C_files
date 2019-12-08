#include <stdio.h>
#include <stdlib.h>

struct stack{
  int *buff;
  int top;
  int buff_size;
};

struct stack* init(int buff_size){
  struct stack* s = (struct stack*)malloc(sizeof(struct stack));
  s->buff = (int*)malloc(sizeof(int) * buff_size);
  s->buff_size = buff_size;
  s->top = -1; 
  return s;
}

void push(struct stack *s, int item){
  if(s->top >= s->buff_size){
    printf("Overflow. Stack is full!");
    return;
  }
  s->top = s->top + 1;
  s->buff[s->top] = item;
}

int pop(struct stack *s){
  if(s->top < 0){
    printf("Stack is empty!");
    return -1e9;
  }
  int res = s->buff[s->top];
  s->top = s->top - 1;
  return res;
}

void display(struct stack *s){
  if(s->top == -1){
    printf("Stack is empty!");
    return;
  }
  for(int i=s->top; i>=0; i--){
    printf("%d\n", s->buff[i]);
  }
}


int main(){
  struct stack *s = init(128);
  push(s, 5);
  push(s, 10);
  push(s, 15);

  display(s);
  printf("\n");

  printf("%d\n", pop(s));
  printf("\n");

  display(s);

return 0;
}
