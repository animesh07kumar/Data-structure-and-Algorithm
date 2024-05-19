#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node* next_address;
   struct node* per_address;
};
void free_space(struct node* str){
    free(str);
}
void insert_at_last(struct node** str, int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* tri;
    if(!new_node){
        printf("Memory allocation fail");
        return;
    }
    new_node->data = value;
    new_node->next_address = NULL;
    if(*str == NULL){
        *str = new_node;
        new_node->per_address = NULL;
    }
    else{
        tri = *str;
        while(tri->next_address != NULL)
            tri = tri->next_address;
        
        tri->next_address = new_node;
        new_node->per_address = tri;
    }
}
void print_linklist(struct node* first_address){
    while(first_address){
        printf("%d ",first_address->data);
        first_address = first_address->next_address;
    }
    return;
}

struct node* delete_first_node(struct node** str){
    struct node* tri;
    if(*str == NULL){
        printf("\nList is empty\n");
        return NULL;
    }
    else{
        tri = *str;
        *str = tri->next_address;
        free(tri->per_address);
        free(tri);
        return *str;
    }
}
// void freeing_all_node(struct node** str){
//      struct node* tri,cap;
//          tri = str;
//          cap = NULL;
//      while(tri){
//         cap = tri;
//         tri = tri->next_address;
//         free(cap);
//      }
//    return;
// }
int main(){
    struct node* start = NULL;  
    // int n;
    // printf("No of value : ");
    // scanf("%d",&n);
    // printf("Enter Value of Data\n");
    // for(int i = 0;i<n;i++){
    //     int val = 0;
    //     insert_at_last(&start,scanf("%d",&val));
    // }
    insert_at_last(&start,10);
    insert_at_last(&start,20);
    insert_at_last(&start,30);
    insert_at_last(&start,40);
    insert_at_last(&start,50);
    insert_at_last(&start,60);
    insert_at_last(&start,70);
    insert_at_last(&start,80);
    insert_at_last(&start,90);
    print_linklist(start);
    return 0;
}
