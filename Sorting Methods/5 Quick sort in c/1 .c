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
int quick_sort(int* arr, int n,int s){
    // recusion make this code such a way that it can be called again and again
    // three point 2 point hovering trought and last point
    int mark;
    for(int i=0;i<n;i++){
        
            // two hovering point are this
            // swap only in case when first element is small
            if(arr[i]>arr[n-1]){
            mark = arr[i];    
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
    
    quick_sort(arr,n);
    printf("Final sorted result\n");
    print_array(arr,n);
    
    free(arr);
    return 0;

}