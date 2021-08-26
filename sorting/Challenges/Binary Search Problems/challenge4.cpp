/*
Search element in sorted and rotated array

we are given an asending sorted array that has been rotated from a pivot point(unknown to us)
and element x. search for x in the array with complexity less than that of linear search.
*/

/*

original array 10 20 30 40 50
rotated array  30 40 50 10 20

ans index  ; 3

1. find pivot point
2. apply binary search in left half.
3. apply binary search in right half.

arr[pivot-1] < arr[pivot] > arr[pivot+1].
*/

#include<iostream>
using namespace std;

int searchInRotated(int arr[] , int key, int left , int right){
    if(left > right){
        return -1;
    }

    int mid = (left + right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){
        if(key >= arr[left] && key <= arr[mid] ){
            return searchInRotated(arr, key,left,mid-1);
        }
            return searchInRotated(arr, key,mid+1,right);
    }
    if (key >= arr[mid] && key <= arr[right]){
        return searchInRotated(arr,key,mid+1 ,right);
    }
        return searchInRotated(arr,key,left ,mid-1);
}


int main(){
    int arr[] = {6,7,8,9,10,1,2,5};
    int key = 1;
    cout << searchInRotated(arr , key , 0,7);
}