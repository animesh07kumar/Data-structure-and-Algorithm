#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct queue{
    int count;
    Node* front;
    Node* rear;
}Queue;

Queue* create_queue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if(!queue){
        printf("Memory Allocation is failed");
        exit(-1);
    }
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
bool is_empty(Queue* queue){
    return queue->front == NULL;
}
void enqueue(Queue* queue, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node){
        printf("Memory Allocation failed");
        exit(-1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(is_empty(queue)){
        queue->front = new_node;
        queue->rear = new_node;
    }
    else{
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->count++;
}
int dequeue(Queue* queue){
    if(is_empty(queue)){
        printf("Queue is empty");
        exit(-1);
    //  return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->count--;
    return data;
}
int size_of(Queue* queue){
    return queue->count;
}
void displaying_queue(Queue* queue){
    printf("\nPrintting Queue\n");
    Node* temp = queue->front;
    while(temp != NULL){

        printf("%d ",temp->data);
        temp = temp->next;
    }
    return;
}
void distroying_queue(Queue* queue){
    Node* temp;
    temp = NULL;
    while(queue->front != NULL){
        temp = queue->front;
        free(temp);
        queue->front = queue->front->next;
    }
    free(queue);
    printf("\nQueue is now been fully dequeued\n");
    return;
}
int main(){
    Queue* MyQueue = create_queue();
    enqueue(MyQueue, 10);
    enqueue(MyQueue, 20);
    enqueue(MyQueue, 30);
    enqueue(MyQueue, 40);
    displaying_queue(MyQueue);
    printf("\nnew line\n");
    printf("%d ",dequeue(MyQueue));
    printf("%d ",size_of(MyQueue));
    printf("%d ",dequeue(MyQueue));
    printf("%d ",dequeue(MyQueue));
    printf("%d ",dequeue(MyQueue));
    printf("%d ",dequeue(MyQueue));

    enqueue(MyQueue, 11);
    enqueue(MyQueue, 21);
    enqueue(MyQueue, 31);
    enqueue(MyQueue, 41);
    
    distroying_queue(MyQueue);

    displaying_queue(MyQueue);

    return 0;
}
