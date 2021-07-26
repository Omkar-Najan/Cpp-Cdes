#include<iostream>
using namespace std;
/*
Find First and last occurance of array
*/

int firstocc(int arr[] , int n,int i,int key){
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstocc(arr , n,i+1,key);

}


int lastocc(int arr[] , int n,int i,int key){
    if( i==n){
        return -1;
    }
    int restArray = lastocc(arr,n,i+1,key);
    if(restArray != -1){
        return restArray;
    }
    if(arr[i] == key){
        return i;
    }
    return -1;
}

int main(){
    int arr[] = {1,5,3,4,5,6,5,8};
    int key = 5;
    int i = 0;
    int n = 8;
    cout << lastocc(arr,n,i,key);
    return 0;
}