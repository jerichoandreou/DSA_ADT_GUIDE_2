#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);

int main(void){
    List L;
    initialize(&L);

    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 30, 2);
    insertPos(&L, 40, 1);

    display(&L);
    printf("\n");

    deletePos(&L, 2);

    display(&L);
    printf("\n");

    printf("%d\n", locate(&L, 20));
    printf("%d\n", retrieve(&L, 1));

    makeNULL(&L);

    return 0;
}

void initialize(List *L){
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L,int data,int position){
    if(position > L->count || position < 0){
        printf("INVALID POSITION");
    }
    if(L->count == L->max){
        resize(L);
    }
    for(int i = L->count;i > position;i--){
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L,int position){
    if(position < 0 || position > L->count){
    	printf("INVALID INDEX");
	}
	if(L->count == MAX){
		resize(L);
	}
	int i;
	for(i = position-1;i  < L->count-1;i++){
		L->elemPtr[i] = L->elemPtr[i + 1];
	}
	L->count--;
}

int locate(List *L,int data){
	int i;
	for(i = 0;i < L->count;i++){
		if(data == L->elemPtr[i]){
			return i + 1;
		}
	}
	
	return -1;
}

int retrieve(List *L,int position){
	if(position < 0 || position > L->count){
		printf("POSITION INVALID");
	}
	return L->elemPtr[position];
}


void resize(List *L){
    int newMax = L->max * 2;

    L->elemPtr = (int*)realloc(L->elemPtr, newMax * sizeof(int));
    if(L->elemPtr == NULL){
        printf("Resize failed!");
        return;
    }

    L->max = newMax;
}

void makeNULL(List *L){
	free(L->elemPtr);
	L->count = 0;
	L->elemPtr = NULL;
	L->max = 0;
}

void display(List* L){
	int i;
	for(i = 0;i < L->count;i++){
		printf("%d ",L->elemPtr[i]);
	}
}

