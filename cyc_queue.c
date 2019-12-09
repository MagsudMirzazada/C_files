#include <stdio.h>
#include <stdlib.h>

struct queue{
    int *buff;
    int front;
    int rear;
    int count;
    int buff_size;
};

struct queue* init(int buff_size){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->buff = (int *)malloc(sizeof(int) * buff_size);
    q->buff_size = buff_size;
    q->front = q->rear = 0;
    q->count = 0;
    return q;
}

void enqueue(struct queue* q, int item){
    if(q->count < (q->buff_size - 1)){
        q->buff[q->rear] = item;
        q->rear = (q->rear+1) % q->buff_size;
        q->count += 1;
    }
}

int dequeue(struct queue* q){
    if(q->count == 0){
        printf("Queue is empty. Cannot act dequeue operation");
        return -1e9;
    }
    int res = -1e9;
    if(q->count > 0){
        res = q->buff[q->front];
        q->front = (q->front + 1) % q->buff_size;
        q->count = (q->count) - 1;
    }
    return res;
}

void destroy_queue(struct queue* q){
    free(q->buff);
    free(q);
}

int max_element(struct queue* q){
  int i = q->front;
  int max = q->buff[q->front];
  int c = q->count;
  while(c--){
    if (q->buff[i] > max){
      max = q->buff[i];
    }
    i = (i+1) % q->buff_size;
  }
  return max;
}

int min_element(struct queue* q){
  int i = q->front;
  int min = q->buff[q->front];
  int c = q->count;
  while(c--){
    if(q->buff[i] < min){
      min = q->buff[i];
    }
    i = (i+1) % q->buff_size;
  }
  return min;
}

int search(struct queue* q, int data){
  int i = q->front;
  int c = q->count;
  while(c--){
    if (q->buff[i] == data){
      return i;
    }
    i = (i+1) % q->buff_size;
  }
  return -1e9;
}

void display(struct queue* q){
    if(q->count == 0){
        printf("Queue is empty");
        return;
    }
    int temp = q->front;
    while(temp != q->rear){
      printf("%d\n", q->buff[temp]);
      temp = (temp+1) % q->buff_size;
      }
      printf("\n");
}

int main(){
    struct queue* q = init(16);

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);
    enqueue(q, 25);

    display(q);

    printf("Deqeueud: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    enqueue(q, 30);
    enqueue(q, 35);
    display(q);
    
    printf("It is the max element in queue: %d\n",  max_element(q));
    printf("It is the min element in queue: %d\n", min_element(q));

    printf("The position of %d in the queue is %d", max_element(q), search(q, max_element(q)));

return 0;
}
