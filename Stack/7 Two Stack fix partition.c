#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
typedef struct{
    int top1, top2, type;
    int arr[MAX_SIZE];
}TwoStack;
TwoStack* create_stack(int type){
    TwoStack* stack = (TwoStack*)malloc(sizeof(TwoStack));
    if(!stack){
        printf("Memory not allocated for stack");
        exit(-1);
    }
    stack->top1 = -1;
    stack->type = type;
    if(type == 1){
        stack->top2 = (MAX_SIZE/2) -1;
    }
    else if(type == 2){
        stack->top2 = MAX_SIZE ;
    }
    
    return stack;
}
bool is_full1(TwoStack* stack){
    return stack -> top1 == (MAX_SIZE/2)-1;
}
bool is_full2(TwoStack* stack){
    
    if(stack->type == 1) return stack -> top2 == MAX_SIZE -1; 
    else return stack -> top2 == (MAX_SIZE/2);
}
bool is_empty1(TwoStack* stack){
    return stack->top1 == -1;
}
bool is_empty2(TwoStack* stack){
    if(stack->type == 1) return stack -> top2 == (MAX_SIZE/2) -1;
    else return stack -> top2 == (MAX_SIZE);
}
void push1(TwoStack* stack, int data){
    if(is_full1(stack)){
        printf("Stack1 is full");
        exit(-1);
    }
    stack->arr[++stack->top1] = data;
    return ;
}
void push2(TwoStack* stack, int data){
    if(is_full2(stack)){
        printf("Stack2 is full");
        exit(-1);
    }
    if(stack->type == 1)
        stack->arr[++stack->top2] = data;
    else
        stack->arr[--stack->top2] = data;
}
int pop1(TwoStack* stack){
    if(is_empty1(stack)){
        printf("Stack1 is empty");
        exit(-1);
    }
    int data = stack->arr[stack->top1--];
    return data;
}
int pop2(TwoStack* stack){
    if(is_empty2(stack)){
        printf("Stack2 is full");
        exit(-1);
    }
    int data;
    if(stack->type == 1){
        data = stack->arr[stack->top2--];
    }
    else{
        data = stack->arr[stack->top2++];
    }
    return data;
}
void print_stack(TwoStack* stack){
    printf("\nPrintting Stack 1\n");
    for(int i = 0;i <= stack-> top1;i++){
        printf("%d ",stack->arr[i]);
    }
    printf("\nPrintting Stack 2\n");
    if(stack->type==1){
        for(int j = MAX_SIZE/2;j<=stack->top2;j++){
            printf("%d ",stack->arr[j]);
        }
    }
    else{
        for(int k = MAX_SIZE - 1;k>=stack->top2;k--){
            printf(" %d",stack->arr[k]);
        }
    }
    return;
}
int main(){
    int t;
    printf("Enter type : ");
    scanf("%d",&t);

    TwoStack* stack = create_stack(t);

    push1(stack,1);
    push1(stack,2);
    push1(stack,3);
    push1(stack,4);
    push1(stack,5);

    push2(stack,10);
    push2(stack,20);
    push2(stack,30);
    push2(stack,40);
    push2(stack,50);

    printf("poped from stack 1 is equal to %d",pop1(stack));
    printf("poped from stack 1 is equal to %d",pop1(stack));
    printf("poped from stack 2 is equal to %d",pop2(stack));
    printf("poped from stack 2 is equal to %d",pop2(stack));

    print_stack(stack);
    return 0;
}