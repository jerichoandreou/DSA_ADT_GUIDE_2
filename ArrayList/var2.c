#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L,int data, int position);
void deletePos(EPtr L,int position);
int locate(EPtr L,int data);
int retrieve(EPtr L,int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    Etype myList;
    EPtr L = &myList;

    initialize(L);

    insertPos(L,10,1);
    insertPos(L,30,2);
    insertPos(L,50,3);
    display(L);

    insertPos(L,20,2);
    display(L);

    deletePos(L,3);
    display(L);

    printf("%d\n", locate(L,50));
    printf("%d\n", retrieve(L,2));

    insertSorted(L,40);
    display(L);

    makeNULL(L);
    display(L);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L,int data, int position){
    if(position >= 1 && position <= L->count + 1 && L->count < MAX){
        int i;
        for(i = L->count; i >= position; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position - 1] = data;
        L->count++;
    } else {
        printf("INVALID INSERT\n");
    }
}

void deletePos(EPtr L,int position){
    if(position >= 1 && position <= L->count){
        int i;
        for(i = position - 1; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    } else {
        printf("INVALID DELETE\n");
    }
}

int locate(EPtr L,int data){
    int pos = -1;
    int i = 0;
    while(i < L->count && pos == -1){
        if(L->elem[i] == data){
            pos = i + 1;
        }
        i++;
    }
    return pos;
}

int retrieve(EPtr L,int position){
    int value = -1;
    if(position >= 1 && position <= L->count){
        value = L->elem[position - 1];
    } else {
        printf("INVALID POSITION\n");
    }
    return value;
}

void insertSorted(EPtr L, int data){
    if(L->count < MAX){
        int pos = 0;
        while(pos < L->count && L->elem[pos] < data){
            pos++;
        }
        int i;
        for(i = L->count; i > pos; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[pos] = data;
        L->count++;
    } else {
        printf("LIST FULL\n");
    }
}

void display(EPtr L){
    if(L->count > 0){
        int i;
        for(i = 0; i < L->count; i++){
            printf("%d ",L->elem[i]);
        }
        printf("\n");
    } else {
        printf("LIST EMPTY\n");
    }
}

void makeNULL(EPtr L){
    L->count = 0;
}
