#include<iostream>
using namespace std;

/*
for the given array and integers K and X, find the maximu sum subarray of size k and having sum less than X.
*/

/*
approach 1: compute sum of all possible subarrays of size K. O(n*k).
approach 2:  sliding window
    1. calculte sum of first k ele.
    2. initiate ans with sum
    3. iterate over rest of array. keep adding in sum and removing one from start.
    compare new sum with ans in each iteration.
    time complexity O(n);
*/

int MaxSumSubarray(int arr[] , int n ,int k ,int x){
    int ans = 0,sum =0;
    for(int i =0;i<k;i++){
        sum  += arr[i];
    }
    if(sum < x){
    ans = sum;
    }

    for(int i = k;i<n;i++){
        sum  = sum - arr[i-k];
        sum  = sum + arr[i];

        if(sum < x ){
            ans = max(ans , sum);
        }

    }

    return ans;
}

int main(){

    int arr[] = {7,5,4,6,8,9};
    int k = 3;
    int x = 20;
    int n = 6;

    cout << MaxSumSubarray(arr,n,k,x);
}