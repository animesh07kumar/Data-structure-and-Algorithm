#include<iostream>
using namespace std;
int print_array(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    cout<<"\n";
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
void merge_operation(int* n_arr, int f, int m, int l){
    int segment1 = m-f+1;
    int segment2 = l-m;
    int* left = new int[segment1];
    int* right = new int[segment2];
    int i,j,k;
    for(i=0;i<segment1;i++)
    left[i] = n_arr[f+i];
    for(j=0;j<segment2;j++)
    right[j] = n_arr[m+1+j];
    i = 0;
    j = 0;
    k = f;
    while(i<segment1 && j<segment2){
        if(left[i]<right[j]){
            n_arr[k] = left[i];
            i++;
            k++;
        }
        else{
            n_arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i<segment1){
        if(left[i]<right[j]){
            n_arr[k] = left[i];
            i++;
            k++;
        }
    }
    while(j<segment2){
        if(right[j]<left[i]){
            n_arr[k] = right[j];
            j++;
            k++;
        }
    }
    delete[] right;
    delete[] left;
}
int merge_sort(int* n_arr,int f, int l){
    // if(f<l) return *c_arr;
    if(f<l){
        int m = (f+l)/2;
        merge_sort(n_arr,f,m);
        merge_sort(n_arr,m+1,l);
        merge_operation(n_arr,f,m,l);
        
    }
    return 0;
}
int count_2o(int* arr, int n){
    // count_2o includes count and and element value with no of its occurance in accending order
    int num = count(arr,n);
    int ele_count = 0;
    int* n_arr = new int[num];
    for(int i=0;i<n;i++){
    int flag = 0;
        for(int j=0;j<i;j++){
            if(arr[i]== arr[j]){
                flag = 1; 
                break;
            }         
        }
        if(flag == 0){
            n_arr[ele_count] = arr[i];
            ele_count++;
        }
    }
    print_array(n_arr,num);
    merge_sort(n_arr,0,num - 1);
    print_array(n_arr,num);
    int* c_arr = new int[num];
    for(int i=0;i<num;i++){
        c_arr[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<num;j++){
            if(arr[i] == n_arr[j]){
                c_arr[j] += 1;
                break;
            }
        } 
    }
    cout<<"Result of Count sort\n";
    for(int k=0;k<num;k++){
        for(int j=0;j<c_arr[k];j++){
            cout<<n_arr[k]<<" ";
        }
    }
    delete[] c_arr;
    delete[] n_arr;
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
    
    printf("Different element count : %d\n",count(arr,n));
    count_2o(arr,n);
    
    delete[] arr;
    return 0; 
}