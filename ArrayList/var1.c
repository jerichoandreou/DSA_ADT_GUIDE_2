#include <stdio.h>
#define MAX 10
//still needs butterfly method and error checking
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

int main(void){
    List L;
	
	L = initialize(L);
	L = insertPos(L,20,1);
	L = insertPos(L,99,2);
	L = insertPos(L,33,3);
	
	display(L);
	L = deletePos(L,3);
	display(L);
	L = insertSorted(L,10);
	display(L);
	return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data,int position){
    if(position < 1 || position > L.count + 1){
        printf("POSITION INVALID.");
    }
    else if(L.count == MAX){
        printf("List is full.");
    }

    for(int i = L.count;i >= position;i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position - 1] = data;
    L.count++;
    return L;
}

List deletePos(List L,int position){
    if(position < 1 || position > L.count){
        printf("POSITION INVALID");
    }
    else if(L.count == 0){
        printf("List is empty");
    }
    for(int i = position - 1;i < L.count - 1;i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L,int data){
    if(L.count == 0){
        printf("List is empty");
    }
    for(int i = 0;i < L.count;i++){
        if(data == L.elem[i]){
            return i + 1;
        }
    }
    return -1;
}

List insertSorted(List L,int data){
	int pos = 0;
	int i;
	if(L.count == MAX){
		printf("List is full");
		return L;
	}
	
	while(pos < L.count && L.elem[pos] < data){
		pos++;
	}
	
	for(i = L.count;i > pos;i--){
		L.elem[i] = L.elem[i-1];
	}
	L.elem[pos] = data;
	L.count++;
	
	return L;
}

void display(List L){
    if(L.count == 0){
        printf("List is empty");
    }

    for(int i = 0;i < L.count;i++){
        printf("%d ",L.elem[i]);
    }
}