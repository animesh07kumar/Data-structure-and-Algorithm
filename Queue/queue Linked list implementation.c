#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    Node* next;
}Node;

typedef struct queue{
    int count;
    Queue* front;
    Queue* rear;
}Queue;

void create_queue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue){
        printf("Memory Allocation is failed");
        exit(-1);
    }
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
}
bool is_empty(Queue* queue){
    
}