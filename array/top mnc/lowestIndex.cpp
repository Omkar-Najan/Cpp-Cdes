#include "bits/stdc++.h"
using namespace std;

// fist repeting element (amazon, oracle)
// given an array of size N. task os to find first repeting element
// in array of integers so that element occures more than once and index of first occurance is smallest.

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    
    const int N = n+1 ;
    int idx[N];
    for(int i = 0;i<N;i++){
        idx[i] = -1;
    }
    int minidx = 999999;
    
    for(int i = 0;i<n;i++){
        if(idx[a[i]] != -1){
            minidx = min(minidx,idx[a[i]]);
        }
        else{
            idx[a[i]] = i;
        }
    }
    
    if(minidx == 999999){
        cout << "-1" << endl;
    }
    else{
        cout << minidx+1 << endl;
    }
    
    return 0;
}