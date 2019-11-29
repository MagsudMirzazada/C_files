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

void display(struct queue* q){
    if(q->count == 0){
        printf("Queue is empty");
    }
    else{
        int temp = q->front;
        while(temp != q->rear){
            printf("%d\n", q->buff[temp]);
            temp++;
        }
    }
    printf("\n");
}

int main(){
    struct queue* q = init(16);
    enqueue(q, 5);
    enqueue(q, 10);
    display(q);
    printf("%d\n", dequeue(q));
    //printf("%d\n", dequeue(q));
    //display(q);

return 0;
}