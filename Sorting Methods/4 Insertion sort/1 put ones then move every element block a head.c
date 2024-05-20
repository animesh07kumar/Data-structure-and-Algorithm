
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
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
// int shifting(int* arr, int SFI, int SuTI){ 
//     // front to back
//     int* Pointer = &arr[SFI];  
//     for(int i=SFI;i<SuTI;i++){
//         int* prevent = Pointer;
//         *Pointer = arr[i+1];
//         arr[i+1] = *prevent;
//     }
//     return 0;
// }
void insertion_sort(int* arr, int n){
    for(int i=1;i<n;i++){ 
            int j; 
            int current_value = arr[i];
            printf("Initial copy %d\n",current_value);
            for(j=0 ; j<i ; j++){
                if(arr[i-j]<arr[i-j-1]){
                    arr[i-j] = arr[i-j-1];
                    print_array(arr,n);
                    
                }
            }                  
            arr[i-j-1] = current_value;
            print_array(arr,n);    
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