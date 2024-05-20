#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
       head = newNode;
       head->next = head; 
        return head;
    }
    struct Node* tri = head;
    while(tri->next != head){
        tri = tri->next;
    }
    tri->next = newNode;
    newNode->next = head;
    return head;
    // newNode->next = head->next;
    // head->next = newNode;
    // return newNode;
}

// void display(struct Node* head) {
//     if (head == NULL) {
//         printf("Circular linked list is empty.\n");
//         return;
//     }
//     struct Node* current = head->next;
//     printf("Circular linked list: ");
//     do {
//         printf("%d ", current->data);
//         current = current->next;
//     } while (current != head->next);
//     printf("\n");
// }
// some where memory leaked
// void display(struct Node* head) {
//     if (head == NULL) {
//         printf("Circular linked list is empty.\n");
//         return;
//     }
//     struct Node* temp = head;
//     printf("Displaying circular linked list");
//     while(temp -> next != head){
//         printf("%d ",temp->data);
//         temp = temp-> next;
//     }
//     printf("%d ",temp->data);
//     free(temp);  // ---> this line causes a memory leak 
    
//     return ;
// }
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Displaying circular linked list: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}
struct Node* del_start_node(struct Node* head){
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        exit(-1);
    }
    struct Node* current = head;
    while (current->next != head){
        current = current->next;
    }
    struct Node* start_node = current->next;
    current -> next = head->next;
    free(start_node);
    return current->next;
}
void del_end_node(struct Node* head){
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current->next->next != head){
        current = current->next;
    }
    struct Node* end_node = current->next;
    current -> next = head;
    free(end_node);
    
}
void freeCircularLinkedList(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* current = head->next;
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}
int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    display(head);
    printf("Deleting from end\n");
    del_end_node(head);
    display(head);
    printf("Deleting from beginning\n");
    head = del_start_node(head);
    display(head);
    freeCircularLinkedList(head);
    
    

    return 0;
}