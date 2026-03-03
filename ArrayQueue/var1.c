#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = 0;
    q->rear = -1;
    
    return q;
}

bool isFull(Queue* q){
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;
}

void enqueue(Queue* q,int value){
    if(isFull(q)){
        printf("LIST IS FULL");
    }

    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("LIST IS EMPTY");
    }
    int temp;
    temp = q->list.items[q->front];
    if(q->list.count == 1){
        q->front = 0;
        q->rear = -1;
    }else{
        q->front = (q->front + 1) % MAX; 
    }
    q->list.count--;
    return temp;
}

int front(Queue* q){
    if(isEmpty(q)){
        printf("List is empty");
    }
    return q->list.items[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("List is empty");
    }
    int index = q->front;
    printf("FRONT -> ");
    for(int i = 0;i < q->list.count;i++){
        printf("%d ",q->list.items[index]);
        index = (index + 1) % MAX;
    }
    printf("-> REAR\n");
}

int main(void){
    Queue* q = initialize();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,67);
    enqueue(q,32);
    enqueue(q,56);
    display(q);
    printf("Dequeue:\n");
    dequeue(q);
    dequeue(q);
    display(q);

    return 0; 
}