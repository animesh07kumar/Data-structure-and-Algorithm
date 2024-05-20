#include<iostream>
using namespace std;
int print_array(int arr[],int n){
    cout<< "Array\n";
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
int merge_operation(int arr[],int f, int m, int l){
    int i,j,k;
    int segment1 = m-f+1;
    int segment2 = l-m;
    int left[segment1];
    int right[segment2]; // giving value to array is important
    for(i=0;i<segment1;i++)
        left[i] = arr[f+i];
    for(j=0;j<segment2;j++)
        right[j] = arr[m+1+j];
    i = 0;
    j = 0;
    k = f;

    while(i<segment1 && j<segment2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<segment1){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
    }
    while(j<segment2){
        if(right[j]<left[i]){
            arr[k] = right[j];
            j++;
            k++;
        }    
    }
    return 0;
}
int merge_sort(int arr[],int f, int l){
    if(f<l){
        int m = (f+l)/2;
        merge_sort(arr,f,m);
        merge_sort(arr,m+1,l);
        merge_operation(arr,f,m,l);
    }
    return 0;
}
int main(){
    int n;
    cout<<"Enter no of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    print_array(arr,n);

    return 0;
}