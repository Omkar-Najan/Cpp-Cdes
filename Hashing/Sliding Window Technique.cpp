#include<iostream>
#include<vector>
using namespace std;

/*
calculate minimum sum of k consequtive elements.
use sliding window technique.

Approach: 
    1. compute sum of first k elements.
    2. while increasing subtract i-1 element and add i + k -1 in previous sum, that will be current sum.
    3. 
*/
#define rep(i,a,b) for(int i = a;i<b;i++)


int main(){
    int n,k;
    cin >> n>>k;

    vector<int> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    int s = 0 , ans = INT_MAX;
    rep(i,0,k){
        s += a[i];
    }

    ans = min(ans, s);
    rep(i,1,n-k+1){
        s -= a[i-1];
        s += a[i+k-1];
        ans = min(ans ,s); 
    }

    cout << ans << endl;
    
}