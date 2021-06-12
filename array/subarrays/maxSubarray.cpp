#include<iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int maxSum = INT_MIN;


    // brut force approach
    // for(int i = 0; i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum = 0;
    //         for(int k = i;k<=j;k++){
    //             sum += a[k];
    //             // cout << a[k]<<" ";
    //         }
    //         // cout << endl;
    //         maxSum = max(maxSum , sum);
    //     }
    // }

    // Cumuative sum approach.
    // make a new array by adding all the elememts before that number.
    // eg. -1 4 7 2
    // cummulative sum array eg. -1 3 10 12

    // int currsum[n+1];
    // currsum[0] = 0;
    // for(int i = 1;i<=n;i++){
    //     currsum[i] = currsum[i-1]+ a[i-1];
    // }

    // for(int i = 1;i<=n;i++){
    //     int sum = 0;
    //     for(int j=0; j<i ;j++){
    //         sum = currsum[i] - currsum[j];
    //         maxSum = max(sum,maxSum);
    //     }
    // }


    // kadanes algorithm
    // Best Approach. 
    
    int currsum =0;
    for(int i = 0;i<n;i++){
        currsum += a[i];
        if(currsum < 0){
            currsum = 0;
        }
        maxSum = max(maxSum , currsum);
    }
    cout << maxSum;
    return 0;
}  