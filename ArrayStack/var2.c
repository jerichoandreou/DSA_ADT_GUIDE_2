#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack* initialize(){
    Stack* s = malloc(sizeof(Stack));
    s->top = MAX;
    return s;
}

bool isFull(Stack* s){
    return s->top == 0;
}

bool isEmpty(Stack* s){
    return s->top == MAX;
}

void push(Stack *s,int value){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    s->top--;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    int val = s->items[s->top];
    s->top++;
    return val;
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    for(int i = s->top; i < MAX; i++){
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main(){
    Stack* s = initialize();

    push(s,10);
    push(s,20);
    push(s,30);

    display(s);

    printf("Pop: %d\n", pop(s));
    display(s);

    return 0;
}