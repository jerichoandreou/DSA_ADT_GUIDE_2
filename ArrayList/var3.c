#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L);
List insertPos(List L,int data,int position);
List deletePos(List L,int position);
int locate(List L, int data);
List insertSorted(List L,int data);
void display(List L);
List resize(List L);

int main(){
    List L;
    L = initialize(L);

    L = insertPos(L,10,1);
    L = insertPos(L,30,2);
    L = insertPos(L,50,3);
    display(L);

    L = insertPos(L,20,2);
    display(L);

    L = deletePos(L,3);
    display(L);

    printf("%d\n", locate(L,50));

    L = insertSorted(L,40);
    display(L);

    free(L.elemPtr);
    return 0;
}

List initialize(List L){
    L.elemPtr = malloc(LENGTH * sizeof(int));
    if(L.elemPtr != NULL){
        L.max = LENGTH;
        L.count = 0;
    }
    return L;
}

List insertPos(List L,int data,int position){
    if(position >= 1 && position <= L.count + 1){
        if(L.count == L.max){
            L = resize(L);
        }
        if(L.count < L.max){
            int i;
            for(i = L.count; i >= position; i--){
                L.elemPtr[i] = L.elemPtr[i - 1];
            }
            L.elemPtr[position - 1] = data;
            L.count++;
        }
    } else {
        printf("INVALID INSERT\n");
    }
    return L;
}

List deletePos(List L,int position){
    if(position >= 1 && position <= L.count){
        int i;
        for(i = position - 1; i < L.count - 1; i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--;
    } else {
        printf("INVALID DELETE\n");
    }
    return L;
}

int locate(List L, int data){
    int pos = -1;
    int i = 0;
    while(i < L.count && pos == -1){
        if(L.elemPtr[i] == data){
            pos = i + 1;
        }
        i++;
    }
    return pos;
}

List insertSorted(List L,int data){
    if(L.count == L.max){
        L = resize(L);
    }
    if(L.count < L.max){
        int pos = 0;
        while(pos < L.count && L.elemPtr[pos] < data){
            pos++;
        }
        int i;
        for(i = L.count; i > pos; i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[pos] = data;
        L.count++;
    }
    return L;
}

void display(List L){
    if(L.count > 0){
        int i;
        for(i = 0; i < L.count; i++){
            printf("%d ",L.elemPtr[i]);
        }
        printf("\n");
    } else {
        printf("LIST EMPTY\n");
    }
}

List resize(List L){
    int newMax = L.max * 2;
    int *temp = realloc(L.elemPtr, newMax * sizeof(int));
    if(temp != NULL){
        L.elemPtr = temp;
        L.max = newMax;
    } else {
        printf("RESIZE FAILED\n");
    }
    return L;
}
