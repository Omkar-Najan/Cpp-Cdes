#include<iostream>
#include<algorithm>
using namespace std;
/*
Problem
Given an array, transform the array such that
arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
Input: Given an array.
Output: print the sorted array.
Time Complexity: O(N), single pass
Space Complexity: O(1)

*/

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void Wavesort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if(arr[i]> arr[i+1] && i<=n-2){
            swap(arr,i,i+1);
        }
    }
    return;
}


int main(){
    int arr[]={1,3,4,7,5,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Wavesort(arr,n);
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}