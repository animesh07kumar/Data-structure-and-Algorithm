#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int data;
    struct Node* next;
}Node;
typedef struct {
    Node* top;
    int count;
}Stack;
Stack* Creating(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack){
        printf("Memory not Allocated!");
        exit(1);
    }
    stack->top = NULL;
    stack->count = 0;
    return stack;
}
int isEmpty(Stack* stack){
    return stack->top == NULL;
}
void push(Stack* stack,int data){
    Node* new_node = (Node*)malloc(sizeof(stack));
    if(!new_node){
        printf("Memory Allocation is Failed!");
        exit(1);
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->count++;
    return;
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!");
        exit(1);
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    stack->count--;
    free(temp);
    temp = NULL;
    return data;
}
int peak(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!");
        exit(1);
    }
    return stack->top->data;
}
int size(Stack* stack){
    return stack->count;
}
void freeStack(Stack* stack){
    Node* tri;
    tri = stack->top->next;
    while (tri->next != NULL){
        free(stack->top);
        stack->top = tri;
        tri = tri->next;
    }
    free(stack->top);
    stack->top = NULL;
    free(tri);
    tri = NULL;
    return;
}
int main(){
    Stack* stack = Creating();
    push(stack,10);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    push(stack,50);
    push(stack,60);
    printf("%d ",peak(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    printf("%d ",pop(stack));
    
    
    

    return 0;
}
