#include<iostream>
using namespace std;

/*
fnd the peak element.
for a given array, find the peak element in the array.Peak element is one which is greater than both, left and right elements.
*/

/*
Corner cases : 
    asending array: last ele is peak
    desc array : first ele is peak
    some ele is peak for other arrys.

    10 20 14 2 23 90 67 peak ele - 20 n 90

    use binary search, analyze from 0 to n-1 (indices)
    compute mid and for each mid check if arr[mid] is peak ele.

    else if arr[mid-1] > arr[mid] , check left for peak.
    else arr[mid] < arr [arr+1] , check right for peak .
*/

int peakele(int arr[] , int low,int high, int n){
    int mid = low + (high-low)/2;

    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])){
        return mid;
    }
    else if(mid > 0 && arr[mid-1] > arr[mid]){
        return peakele(arr,low,mid-1, n);
    }
    else{
        return peakele(arr , mid+1 , high,n);
    }

}





int main(){

    int arr[] = {0,6,8,5,7,9};
    int low = 0;
    int high = 5;
    cout << peakele(arr,low,high ,6);
    return 0;
}