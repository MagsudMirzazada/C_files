#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node *init(int data){
  struct node* stack = (struct node*)malloc(sizeof(struct node));
  stack->next = NULL;
  stack->data = data;
  return stack;
}

void push(struct node** head, int data){
  struct node *stack = init(data);
  if(*head == NULL){
    *head = stack;
    return;
  }
  stack->next = *head;
  *head = stack;
}

void pop(struct node** head){
  if(*head == NULL){
    return;
  }
  struct node* temp = *head;
  printf("%d\n", temp->data);
  *head = (*head)->next;
  free(temp);
}

int top(struct node* head){
  return (head)->data;
}

void traverse(struct node* head){
  struct node* temp = head;
  while(temp != NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(){
  struct node* head = NULL;
  push(&head, 5);
  push(&head, 10);
  push(&head, 15);
  
  printf("It is top: %d\n", top(head));
 
  traverse(head);

  pop(&head);
  pop(&head);
  
  printf("\n");

  traverse(head);

return 0; 
}
