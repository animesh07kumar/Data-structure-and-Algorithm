#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
struct node* insertAtBegin(struct node* head,int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode){
            printf("Memory is not allocated. try again");
            exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    // inserting first node to list
    if(head == NULL){
        head = newNode;
        return head;
    }
    // inserting at begining of list 
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    
}
struct node* insertAtEnd(struct node* head,int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode){
            printf("Memory is not allocated. try again");
            exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    // inserting first node to list
    if(head == NULL){
        head = newNode;
        return head;
    }
    // inserting at end of list
    else{
        struct node* tri;
        tri = head;
        while(tri->next != NULL){
            tri = tri->next;
        }
        tri->next = newNode;
        newNode->prev = tri;
        return head;
    }
    
}
struct node* insertAtIndex(struct node* head,int data, int index){
    // int n;
    // printf("Enter Number to insert node(index are counted from 0) : ");
    // scanf("%d",&n);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode){
            printf("Memory is not allocated. try again");
            exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
        struct node* tri, *tri2 = NULL;
        tri = head;
        int index_count = 0;
        while(tri->next != NULL && index_count < index){
            tri = tri->next;
            index_count++;
        }
        if(index_count-1>index){
            printf("List is shorter than index");
            exit(1);
        }
        else if(tri->next == NULL){
            return insertAtEnd(head,data);
        }
        else{
            tri2 = tri->next;
        newNode->next = tri2;
        newNode->prev = tri;
        tri->next = newNode;
        tri2->prev = newNode;
        return head;
        }
        
    
}
// struct node* deletingNode(struct node* head,int data, int index){
//         struct node* tri, *tri2 = NULL ,;
//         tri = head;
//         int index_count = 0;
//         while(tri->next != NULL && index_count <= index){
//             tri = tri->next;
//             index_count++;
//         }
//         if(index_count-1>index){
//             printf("List is shorter than index");
//             exit(1);
//         }
//         else if(tri->next == NULL){
//             insertAtEnd(head,data);
//         }
//         else{
//             tri2 = tri->next;
//         newNode->next = tri2;
//         newNode->prev = tri;
//         tri->next = newNode;
//         tri2->prev = newNode;
//         return head;
//         }
    
// }

void printting_DLL(struct node* head){
    struct node* print_tri = head;
    while(print_tri!= NULL){
        printf("%d ",print_tri->data);
        print_tri = print_tri->next;
    }
    return;
}
int main(){
    struct node* head = NULL;
    
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,20);
    head = insertAtEnd(head,90);
    head = insertAtIndex(head,50,1);
    printting_DLL(head);


    return 0;
}
