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
typedef struct Node{
    int vertex;
    struct Node* next;
}Node;
typedef struct graph{
    int num_vertices;
    Node** adj_lists;
}GraphList;
GraphList* create_graph(int vertices){
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    if(!graph){
        printf("Memory allocation failed for graph");
        // return -1;
        exit(-1);
    }
    graph->num_vertices = vertices;
    graph->adj_lists = malloc(sizeof(Node)*vertices);
    for(int i=0;i<vertices;i++){
        graph->adj_lists[i] = NULL;
    }
    return graph;
}
void adding_edge(GraphList* graph, int ver_1, int ver_2){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> vertex = ver_1;
    temp -> next = graph->adj_lists[ver_2];
    graph->adj_lists[ver_2] = temp;

    temp = (Node*)malloc(sizeof(Node));
    temp -> vertex = ver_2;
    temp -> next = graph->adj_lists[ver_1];
    graph->adj_lists[ver_1] = temp;
    return;
}
int print_graph_list(GraphList* graph){
    for(int i=0;i<graph->num_vertices;i++){
        Node* temp = graph->adj_lists[i];
        printf("-- %d",i);
        while(temp != NULL){
            printf("-> %d",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}
int bfs_iterative(GraphList* graph, int start_vertex){
    int curr_vertex;
    Queue* queue = create_queue();
    enqueue(queue,start_vertex);
    int* visited = (int*)calloc(graph->num_vertices,sizeof(int));
    while(!is_empty(queue)){
        curr_vertex = dequeue(queue);
        if(!visited[curr_vertex]){
            visited[curr_vertex] = 1;
            printf("Visited %d",curr_vertex);
        }
        Node* temp = graph->adj_lists[curr_vertex];
        while(temp != NULL){
            if(!visited[temp->vertex]){
                enqueue(queue,temp->vertex);
                
            }
            temp = temp->next;
        }
    }
    free(queue);
    return 0;
}
int main(){
    int vertices = 6;
    GraphList* graph = create_graph(vertices);
    adding_edge(graph,0,1);
    adding_edge(graph,0,2);
    adding_edge(graph,0,3);
    adding_edge(graph,1,3);
    adding_edge(graph,2,5);
    adding_edge(graph,3,4);
    adding_edge(graph,3,5);
    adding_edge(graph,4,5);

    print_graph_list(graph);

    bfs_iterative(graph,0);

    return 0;
}