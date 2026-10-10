//Stack using array
#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int value){
    if(top == MAX-1){
        printf("Stack is full cannot push %d element \n", value);
    } else{
        stack[++top] = value;
    }
}
void pop(){
    if(top == -1){
        printf("Stack is empty \n");
    } else{
        printf("Popped %d element from the stack \n", stack[top--]);
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty \n");
    }
    else{
        printf("Top element = %d \n", stack[top]);
    }
}
void display(){
    int i;
    if(top == -1){
        printf("Stack is empty \n");
    }else{
        printf("Stack (bottom to start) \n");
        for(i=0; i<=top; i++){
            printf("%d", stack[i]);
            printf("\n");
        }
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    peek();
    pop();
    display();
    pop();
    display();
}