#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i,a,b) for(int i = a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

/*
problem:
    you have given n activities with their start and finish times.
    select the maximum number of activities that can be performed by a single person assumning 
    that a person can only work on single activity at a time.

    sample test cases : 
    3
    10 20 
    12 15
    20 30

    output 
    2

    constraints:
    1 <= n <= 1e5
    1 <= start,end <= 1e9
    start <= end.

*/

/*
Greedy approach
1. if you are at the ith activity, take next activity that ends first.
2. sort activities with respect to end times.
*/


int main(){
    int n; cin >> n;
    vector<vector <int>> v;

    for(int i = 0;i<n;i++){
        int start ,end;
        cin >> start >> end;
        v.push_back({start , end}); // no need to make new vector, this wil make a vector and push it into parent vector
    }

    sort(v.begin(),v.end(),[&](vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }); // custom comparator function to sort in ending order.

    int take = 1;
    int end = v[0][1];

    for(int i=1;i<n;i++){
        if(v[i][0] >= end){
            take ++;
            end = v[i][1];
        }
    }
    cout << take << endl;

}