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

int main(void){
    List L;
    L = initialize(L);

    printf("List:\n");
    L = insertPos(L,10,1);
    L = insertPos(L,30,2);
    L = insertPos(L,40,3);
    display(L);

    printf("\nDeleted list:\n");
    L = deletePos(L,1);
    display(L);

    int pos = locate(L,40);
    printf("\nlocated data:\n%d\n",pos);

    printf("\nInsert Sorted:\n");
    L = insertSorted(L,20);
    L = insertSorted(L,35);
    display(L);

    free(L.elemPtr);
    return 0;
}


List initialize(List L){
  
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L,int data,int position){
   if(position <= 1 || position > L.count + 1){
    printf("INVALID INDEX");
    return L;
   }
   else if(L.count == L.max){
    L = resize(L);
   }
   for(int i = L.count;i > position;i--){
    L.elemPtr[i] = L.elemPtr[i - 1];
   }
   L.elemPtr[position + 1] = data;
   L.count++;
   return L;
}

List deletePos(List L,int position){
    if(position <= 1 || position > L.count){
    printf("INVALID INDEX");
    return L;
   }

   for(int i = position - 1;i < L.count - 1;i++){
    L.elemPtr[i] = L.elemPtr[i + 1];
   }
   L.count--;
   return L;
}

int locate(List L, int data){
    for(int i = 0;i < L.count;i++){
        if(data == L.elemPtr[i]){
            return i + 1;
        }
    }
    return -1;
}

List insertSorted(List L,int data){
    if(L.count == L.max){
        L = resize(L);
    }
    int pos = 0;
    while(pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }
    for(int i = L.count; i > pos; i--){
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[pos] = data;
    L.count++;
    return L;
}

void display(List L){
    if(L.count == 0){
        printf("LIST IS EMPTY");
        return;
    }
    for(int i = 0;i < L.count;i++){
        printf("%d ",L.elemPtr[i]);
    }
}

List resize(List L)
{
    int newMax = L.max * 2;

    int *temp = realloc(L.elemPtr, newMax * sizeof(int));
    if(temp == NULL){
        printf("Memory resize failed\n");
        return L;
    }

    L.elemPtr = temp;
    L.max = newMax;
    return L;
}
