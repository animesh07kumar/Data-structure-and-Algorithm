#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int top;
    int array[MAX_SIZE];
} Stack;
Stack* creating(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack){
        printf("Memory Allocation failed!");
        exit(1);
    }
    stack -> top = -1;
    return stack;
}
int isEmpty(Stack* stack){
    return stack->top == -1;
}
int isFull(Stack* stack){
    return stack->top == MAX_SIZE - 1; // index are from 0 to 99
}
void push(Stack* stack,int data){
    if(isFull(stack)){
        printf("Stack is full!");
        exit(1);
    }
    stack->array[++stack->top] = data;
    return;
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!");
        exit(1);
    }
    return stack->array[stack->top--];
}
void peak(Stack* stack){
    printf("%d ",stack->array[stack->top]);
    return;
}
int size(Stack* stack){
    return stack->top+1;
}
int main(){
    Stack* stack =  creating();
    push(stack,10);
    push(stack,21);
    push(stack,32);
    push(stack,43);
    peak(stack);
    printf("%d " ,pop(stack));

    return 0;
}
