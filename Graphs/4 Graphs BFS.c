#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define QUEUE_SIZE 20

typedef struct Queue{
    int arr[QUEUE_SIZE];
    int front;
    int rear;
}Queue;

Queue* create_queue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue){
        printf("Memory nor allocated for Queue\n");
        exit(-1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
bool is_empty(Queue* queue){
    return (queue->front > queue->rear || queue->rear == -1);
}
bool is_full(Queue* queue){
    return (queue-> rear == QUEUE_SIZE - 1);
}
void enqueue(Queue* queue, int data){
    if(is_full(queue)){
        printf("Queue is full\n");
        return;
    }
    if(is_empty(queue))
        queue->front = 0;
    queue->arr[++queue->rear] = data;
    return;
}
int dequeue(Queue* queue){
    if(is_empty(queue)){
        printf("Cannot Dequeue queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    
    if(queue->front == queue->rear){
        Queue* temp = queue;
        queue = NULL;
        queue = create_queue();
        free(temp);  
    }
    else
        queue->front++;

    return data;
}
// graph list data