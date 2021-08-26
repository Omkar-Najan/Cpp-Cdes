#include<iostream>
using namespace std;

/*
Smallest subarray with sum > x.

for a given array and integer x find the minimum subarray size for which sum > x.
*/
/*
Approach 1: compute sum of all subarrays and check condition. O(n^2).
Approach 2: 
    1. use variables ans, sum, start.
    2. iterate over array and start adding elements to sum
    3. if sum > x, remove element from start.
*/


int smallestSubarrayWIthSum(int arr[] , int n,int x){
    int ans  = 0,sum = 0, minLen = n+1, start  = 0, end = 0;
    while(end < n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < minLen){
                minLen  = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLen;
}

int main(){
    int arr[] = {1,4,35,6,10,19};
    int  x = 51;
    int n = 6;

    cout << smallestSubarrayWIthSum(arr,n,x);
    return 0;
}