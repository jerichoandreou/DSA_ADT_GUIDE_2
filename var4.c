#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L);

int main(void){
    

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
    L->count++;
}