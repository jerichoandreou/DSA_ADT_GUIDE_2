#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct{
    Node* head;
    int count;
} List;

List* initialize();
int isEmpty(List* L);
void insertFirst(List* L, int data);
void insertLast(List* L, int data);
void deleteFirst(List* L);
void deleteLast(List* L);
void deleteAtPos(List* L, int pos);
int retrieve(List* L, int index);
void display(List* L);
void empty(List* L);
void freeList(List* L);

int main(){

    List* L = initialize();

    insertFirst(L,10);
    insertFirst(L,20);
    insertFirst(L,30);
    display(L);

    insertLast(L,56);
    insertLast(L,67);
    display(L);

    deleteFirst(L);
    deleteLast(L);
    display(L);

    deleteAtPos(L,1);
    display(L);

    printf("Retrieved: %d\n", retrieve(L,1));

    empty(L);
    display(L);

    freeList(L);

    return 0;
}

List* initialize(){
    List* L = (List*)malloc(sizeof(List));
    if(L == NULL){
        printf("Allocation unsuccessful\n");
        exit(1);
    }
    L->head = NULL;
    L->count = 0;
    return L;
}

int isEmpty(List* L){
    return (L->head == NULL);
}

void insertFirst(List* L, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = L->head;
    L->head = newNode;
    L->count++;
}

void insertLast(List* L, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(L)){
        L->head = newNode;
    } else {
        Node* current = L->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    L->count++;
}

void deleteFirst(List* L){
    if(isEmpty(L)){
        printf("List empty\n");
        return;
    }

    Node* temp = L->head;
    L->head = temp->next;
    free(temp);
    L->count--;
}

void deleteLast(List* L){
    if(isEmpty(L)){
        printf("List empty\n");
        return;
    }

    if(L->head->next == NULL){
        free(L->head);
        L->head = NULL;
    } else {
        Node* current = L->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    L->count--;
}

void deleteAtPos(List* L, int pos){
    if(pos < 0 || pos >= L->count){
        printf("Invalid position\n");
        return;
    }

    if(pos == 0){
        deleteFirst(L);
        return;
    }

    Node* current = L->head;
    for(int i = 0; i < pos - 1; i++){
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    L->count--;
}

int retrieve(List* L, int index){
    if(index < 0 || index >= L->count){
        printf("Invalid index\n");
        return -1;
    }

    Node* current = L->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }

    return current->data;
}

void display(List* L){
    Node* current = L->head;

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void empty(List* L){
    Node* current = L->head;

    while(current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    L->head = NULL;
    L->count = 0;
}

void freeList(List* L){
    empty(L);
    free(L);
}
