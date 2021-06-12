#include<iostream>
#include <climits>
using namespace std;

int kadane(int arr[] , int n){
    int currentsum = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        currentsum += arr[i];
        if(currentsum < 0){
            currentsum = 0;
        }
        maxsum = max(maxsum,currentsum);
    }
    
    return maxsum;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int wrapsum = 0;
    int nonwrapsum = 0;
    int totalsum = 0;
    nonwrapsum = kadane(arr,n);
    for(int i=0;i<n;i++){
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = totalsum + kadane(arr,n);
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << totalsum;
    cout<< wrapsum;
    return 0;
}