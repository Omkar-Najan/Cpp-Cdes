#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ff first
#define ss second
#define vi vector<int>
/*
IMP

Brute Force O(n^2)
Approach :
    1. Compute Prefix sum in a map
    2. For every key,choose 3 values from all the occurance of partiular presum.
    3. Special case: for presum 0, include them too
*/
int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
    }

    map<int,int> cnt;
    int prefixsum = 0;
    rep(i,0,n){
        prefixsum+= a[i];
        cnt[prefixsum]++;
    }
    int ans = 0;
    map<int , int>:: iterator it;
    for(it = cnt.begin(); it!= cnt.end();it++){
        int c = it->ss;
        ans += (c * c -1)/2;

        if(it->ff == 0){
            ans += it->ss;
        }
    }

    cout << ans << endl;
    return 0;
    
}