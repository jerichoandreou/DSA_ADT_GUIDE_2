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
int main(void){
    Etype myList;   
    EPtr L = &myList; 

    initialize(L);

    insertPos(L, 1, 1);
    insertPos(L, 3, 2);
    insertPos(L, 5, 3);
    display(L);

    insertPos(L, 4, 2);
    display(L);

    deletePos(L, 1);
    display(L);

    insertSorted(L, 8);
    display(L);

    printf("Found at position: %d\n", locate(L, 5));
    printf("Element at position 2: %d\n", retrieve(L, 2));

    makeNULL(L);
    display(L);
   return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L,int data, int position){
    if(position > L->count + 1 || position < 1){
        printf("INVALID POSITION");
    }
    if(L->count == MAX){
        printf("List is Full");
    }
    for(int i = L->count;i >= position;i--){
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position - 1] = data;
    L->count++;
}

void deletePos(EPtr L,int position){
    if(position > L->count + 1 || position < 1){
        printf("INVALID POSITION");
    }
    if(L->count == MAX){
        printf("List is Full");
    }
    for(int i = position - 1;i < L->count - 1;i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L,int data){
    for(int i = 0;i < L->count;i++){
        if(data == L->elem[i]){
            return i + 1;
        }
    }
    return -1;
}

int retrieve(EPtr L,int position){ 
    if(position > L->count + 1 || position < 1){
        printf("INVALID POSITION");
    }
    return L->elem[position - 1];
}

void insertSorted(EPtr L, int data){
	if(L->count == MAX){
		printf("List is full");
	}
	int i;
	int pos = 0;
		while(pos < L->count && L->elem[pos] < data){
			pos++;
		}
		for(i = L->count;i > pos;i--){
		L->elem[i] = L->elem[i - 1]; 
	}
	L->elem[pos] = data;
	L->count++;
	}

void display(EPtr L){
    if(L->count == 0){
        printf("LIST IS EMPTY");
    }
    for(int i = 0;i<L->count;i++){
        printf("%d ",L->elem[i]);
    }

}

void makeNULL(EPtr L){
    L->count = 0;
}