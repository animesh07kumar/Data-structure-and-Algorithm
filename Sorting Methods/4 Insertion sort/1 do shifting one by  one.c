#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}
void print_array(int* arr,int n){
    for(int j = 0; j<n; j++){
        printf("%d ",arr[j]);      
    }
    printf("\n");
    return;
}
void insertion_sort(int* arr, int n){
    // swapping at every check
    // int section;
    for(int i=0; i<n;i++){

        for(int j=0;j<i;j++){
            if(arr[i-j]<arr[i-1-j]){
                swap(&arr[i-j],&arr[i-1-j]); // may here occur error value to pointer 
            }
            else break;
        }

    }

}
int main(){
    int n;
    printf("Enter No of elements : ");
   
    scanf("%d",&n);
     printf("Enter Value of elements\n");
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i<n;i++){
        scanf("%d",&arr[i]);  
        
    }
    
    insertion_sort(arr,n);
    printf("Final sorted result\n");
    print_array(arr,n);
    
    free(arr);
    return 0;

}