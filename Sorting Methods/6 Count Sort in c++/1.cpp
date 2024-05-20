#include<iostream>
using namespace std;
int print_array(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
int count(int* arr, int n){
    int ele_count = 0;
    
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                flag = 1;
            }
        }
        if(flag == 0) ele_count++;
    }
    return ele_count;
}
int count_2o(int* arr, int n){
    // count_2o includes count and and element value with no of its occurance in accending order
   int ele_count = 0;
//    int* c_arr = new int[count(arr,n)];
    int num = count(arr,n);
    int c_arr[num];
    for(int i=0;i<n;i++){
    int flag = 0;
        for(int j=0;j<i;j++){
            if(arr[i]== arr[j]){

                flag = 1; // multiple time flag one hoga yaha // bachne ke leya break karege
                // flag one hote hi break karo
                break;
            }         
        }
        if(flag == 0){
            c_arr[ele_count] = arr[i];
            ele_count++;
        }
   } 
    
    return print_array(c_arr,num); 
}

int count_sort(int* arr, int n){
    int* element_no = new int(count(arr,n));
    int* arr_count = new int[*element_no];
    
    
    delete[] arr_count;
    delete element_no;
    return 0;
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
    // quick_sort(arr,0,n-1);
    // print_array(arr,n);
    printf("Different element count : %d\n",count(arr,n));
    count_2o(arr,n);
    
    delete[] arr;
    return 0; 
}