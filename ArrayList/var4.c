#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);
void insertPos(List *L,int data,int position);
void deletePos(List *L,int position);
int locate(List *L,int data);
int retrieve(List *L,int position);
void resize(List *L);
void makeNULL(List *L);
void display(List* L);

int main(){
    List L;
    initialize(&L);

    insertPos(&L,10,0);
    insertPos(&L,20,1);
    insertPos(&L,30,2);
    display(&L);

    insertPos(&L,15,1);
    display(&L);

    deletePos(&L,2);
    display(&L);

    printf("%d\n", locate(&L,20));
    printf("%d\n", retrieve(&L,1));

    makeNULL(&L);
    return 0;
}

void initialize(List *L){
    L->elemPtr = malloc(LENGTH * sizeof(int));
    if(L->elemPtr != NULL){
        L->max = LENGTH;
        L->count = 0;
    }
}

void insertPos(List *L,int data,int position){
    if(position >= 0 && position <= L->count){
        if(L->count == L->max){
            resize(L);
        }
        if(L->count < L->max){
            int i;
            for(i = L->count; i > position; i--){
                L->elemPtr[i] = L->elemPtr[i - 1];
            }
            L->elemPtr[position] = data;
            L->count++;
        }
    } else {
        printf("INVALID INSERT\n");
    }
}

void deletePos(List *L,int position){
    if(position >= 0 && position < L->count){
        int i;
        for(i = position; i < L->count - 1; i++){
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    } else {
        printf("INVALID DELETE\n");
    }
}

int locate(List *L,int data){
    int pos = -1;
    int i = 0;
    while(i < L->count && pos == -1){
        if(L->elemPtr[i] == data){
            pos = i;
        }
        i++;
    }
    return pos;
}

int retrieve(List *L,int position){
    int value = -1;
    if(position >= 0 && position < L->count){
        value = L->elemPtr[position];
    } else {
        printf("INVALID POSITION\n");
    }
    return value;
}

void resize(List *L){
    int newMax = L->max * 2;
    int *temp = realloc(L->elemPtr, newMax * sizeof(int));
    if(temp != NULL){
        L->elemPtr = temp;
        L->max = newMax;
    } else {
        printf("RESIZE FAILED\n");
    }
}

void makeNULL(List *L){
    if(L->elemPtr != NULL){
        free(L->elemPtr);
        L->elemPtr = NULL;
    }
    L->count = 0;
    L->max = 0;
}

void display(List* L){
    if(L->count > 0){
        int i;
        for(i = 0; i < L->count; i++){
            printf("%d ",L->elemPtr[i]);
        }
        printf("\n");
    } else {
        printf("LIST EMPTY\n");
    }
}
