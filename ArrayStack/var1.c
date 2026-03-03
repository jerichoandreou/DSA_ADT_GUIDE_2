#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack* initialize(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s){
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s,int value){
    if(isFull(s)){
        printf("LIST IS FULL");
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("List is empty");
    }
    int topVal;
    topVal = s->items[s->top];
    s->top--;
    return topVal;
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("List is empty");
    
    }
    int returnVal;
    returnVal = s->items[s->top];

    return returnVal;
}

int top(Stack* s){
    return s->items[s->top];
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("List is empty");
    }
    for(int i = 0;i <= s->top;i++){
        printf("%d ",s->items[i]);
    }
}
int main(void){

    Stack* s = initialize();

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,67);
    display(s);
    printf("\nAFTER POP:\n");
    pop(s);
    pop(s);
    display(s);
    int topval= peek(s);
    printf("\npeek val= %d",topval);

    
    return 0;
}