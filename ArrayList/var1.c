#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data,int position);
List deletePos(List L,int position);
int locate(List L,int data);
List insertSorted(List L,int data);
void display(List L);

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

    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data,int position){
    if(position >= 1 && position <= L.count + 1 && L.count < MAX){
        int i;
        for(i = L.count; i >= position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position - 1] = data;
        L.count++;
    } else {
        printf("INVALID INSERT\n");
    }
    return L;
}

List deletePos(List L,int position){
    if(position >= 1 && position <= L.count && L.count > 0){
        int i;
        for(i = position - 1; i < L.count - 1; i++){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    } else {
        printf("INVALID DELETE\n");
    }
    return L;
}

int locate(List L,int data){
    int pos = -1;
    int i = 0;
    while(i < L.count && pos == -1){
        if(L.elem[i] == data){
            pos = i + 1;
        }
        i++;
    }
    return pos;
}

List insertSorted(List L,int data){
    if(L.count < MAX){
        int pos = 0;
        while(pos < L.count && L.elem[pos] < data){
            pos++;
        }
        int i;
        for(i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[pos] = data;
        L.count++;
    } else {
        printf("LIST FULL\n");
    }
    return L;
}

void display(List L){
    if(L.count > 0){
        int i;
        for(i = 0; i < L.count; i++){
            printf("%d ",L.elem[i]);
        }
        printf("\n");
    } else {
        printf("LIST EMPTY\n");
    }
}
