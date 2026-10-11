//Stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*top=NULL;
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void pop(){
    struct Node*temp;
    if(top == NULL){
        printf("Stack is empty \n");
        return;
    }
    temp = top;
    printf("Popped %d element from stack \n", temp->data);
    top = top->next;
    free(temp); //What is this statement for?
}
void peek(){
    if(top == NULL){
        printf("Stack is empty \n");
    } else{
        printf("Top element = %d \n", top->data);
    }
}
void display(){
    struct Node*t = top;
    if(top == NULL){
        printf("Stack is empty \n");
        return;
    }
    printf("Stack (bottom to start) \n");
    while(t!=NULL){
        printf("%d", t->data);
        printf("\n");
        t = t->next;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    push(90);
    display();
}