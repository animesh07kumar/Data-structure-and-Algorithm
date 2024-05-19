#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ARR_SIZE 20



typedef struct Queue{
    int arr[ARR_SIZE];
    int front;
    int rear;
}Queue;
Queue* create_Queue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue){
        printf("Memory Allocation failed!");
        exit(-1);
    }
    queue -> front = -1;
    queue -> rear = -1;
    return queue;
}
bool is_empty(Queue* queue){
    return queue->rear == -1;
}
bool is_full(Queue* queue){
    return queue->rear == ARR_SIZE -1;
}
void enqueue(Queue* queue ,int data){
    if(is_full(queue)){
        printf("Queue is overflowing\n");
    }
    if(is_empty(queue))
        queue->front = 0;
    queue->arr[++queue->rear] = data;
}
int dequeue(Queue* queue){
    if(is_empty(queue)){
        printf("Queue is empty\n");
    }
    int data = queue->arr[queue->front];
    if(queue->rear == queue->front){
        queue = create_Queue();
    }
    else
        queue->front++;
    return data;
}



int main(){
    Queue* new_queue = create_Queue();
    enqueue(new_queue,10);
    enqueue(new_queue,20);
    enqueue(new_queue,30);
    printf("%d ",dequeue(new_queue));
    enqueue(new_queue,40);
    printf("%d ",dequeue(new_queue));
    printf("%d ",dequeue(new_queue));
    printf("%d ",dequeue(new_queue));
    printf("%d ",dequeue(new_queue));
    
    return 0;
}