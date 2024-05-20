#include<iostream>
using namespace std;
int print_array(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
// divide and conquer
int swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return 0;
}
int partition(int* arr, int first, int last){
    int pivot = arr[last];
    int i = first -1;
    for(int j = first;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    // i++ // i++ sidha i+1 on index pe rakho
    swap(&arr[i+1],&pivot);
    // pivot value hai
    // return pivot;
    return i+1;
}
void quick_sort(int* arr, int first, int last){
    // terminal condition
    if(first>=last){
        return;
    }
    int split = partition(arr,first,last); // taking last as pivot
    quick_sort(arr,first,split-1);
    quick_sort(arr,split+1,last-1);
    
}

int main(){
    int n;
    cout<< "No of Elements : ";
    cin>> n;
    int* arr = new int[n];
    cout<< "Enter Elements"<< "\n";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    quick_sort(arr,0,n-1);
    print_array(arr,n);
    delete[] arr; 
}