#include "bits/stdc++.h"
using namespace std;
int main(){

    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 0;i<n;i++){
       cin >> arr[i];
    }
    arr[n] = -1;
    // given an array a[] for every i from o to n-1 output max[a[0] , a[1],...,a[i]]
    int mx = arr[0];
    for(int i=i;i<n;i++){
        if(mx < arr[i]){
            mx =  arr[i];
        }
        cout << mx << endl;
    }

    // subarrays : 
    // given an array of size[n]. Output sum of each subarray of the given array. 
    // iterate over all the subarrays 
    
    // for(int i = 0;i<n;i++){
    //     int current = 0;
    //     for(int j = i ; j< n;j++){
    //         current+= arr[j];
    //         cout << current << endl;
    //     }
    // }

    // Longest Aritmatic subarray
    // an arithmatic subarray (AP) is an array that contains at least two integers and  differences between consecutive integers are equal.
    // Saraswati has an array of N non negative integers. The i-th integer of the array is Ai. She wants to choose a contiguous arithmatic subarrya
    // from her array has the maximum length. Please help her to determine the length of the longest contiguous arithmatuc subarray. 
    

    int pd = a[1]-a[0], ans=2, j=2, curr = 2;
    while(j<n){
        if(pd == a[j] - a[j-1]){
            curr++;
        }else{
            pd = a[j] - a[j-1];
            curr = 2;
        }
        ans = max(curr , ans);
        j++;
    }
    cout << ans << endl;

    // record Breakers
    // 
    // if(n==1){
    //     cout << "1" << endl;
    //     return 0;
    // }
    // int ans = 0;
    // int mx = -1;
    // for(int i = 0;i<n;i++){
    //     if(a[i] > mx && a[i] > a[i+1]){
    //         ans++;
    //         mx = max(mx,a[i]);
    //     }
    // }
    // cout << ans << endl;
    
    return 0; 
}