#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print_array(int* arr,int n){
    for(int j = 0; j<n; j++){
        printf("%d ",arr[j]);      
    }
    printf("\n");
    return;
}
void selection_sort(int* arr, int n){
    int min_index;
    for(int i = 0; i<n-1;i++){
        arr[min_index] = arr[i]; 
        for(int j=i+1; j<n;j++){
            if(arr[j] < arr[min_index]){
                
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        print_array(arr,n);
    }
    printf("\n");
    return;
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
    
    selection_sort(arr,n);
   
    print_array(arr,n);
    
    free(arr);
    return 0;
}

// error in code