#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int front;
    int rear;
}Queue;

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;

    return q;
}

bool isEmpty(Queue* q){
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q){
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("LIST IS FULL");
      
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("LIST IS EMPTY");

    }
    int temp = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return temp;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("LIST IS EMPTY");
    }
    return q->items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("LIST IS EMPTY");
    }

    int i = q->front;
    printf("FRONT ->");
    while(i != (q->rear + 1) % MAX){
        printf("%d ",q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("-> REAR\n");
}

int main(void){
    Queue* q = initialize();
    
    printf("LIST:\n");
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    display(q);

    return 0;
}