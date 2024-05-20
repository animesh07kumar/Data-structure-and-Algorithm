// radix sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int print_array(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
// used for bigger numbers
int total_digit(int n){
    int number = 0;
    while(n<0){
        n /= 10;
        number++;
    }
    return number;
}
int digit_value(int n, int p){ // p = place 10^0 = 1, 10^1 = 2, 10^2 = 3
    
}
int radix_sort(int* arr, int n){


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
    
    delete[] arr; 
}