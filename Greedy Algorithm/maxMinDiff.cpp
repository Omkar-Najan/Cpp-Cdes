#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// macros defination
#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i,a,b) for(int i = a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

/*
 * You are given an array of A of N elements. You have to remove exactly n/2 elements from array form array A and add it to another array B(initially empty).
 * find maximum and minimum values of difference between these two arrays.
 * we define the difference between these two arrays as
 * sumOf(abs(a[i] - b[i]))
 * 
 * sample test cases:
 *  4 
 * 12 -3 10 0
 * 
 * for max diff
 * -3 0
 * 12 10    25
 * 
 * for min diff
 * -3 12
 * 0 10   5
 * 
*/

/*
Approach Greedy:
To maximize abs(a[i] - b[i])
1. a[i] should be as large as possible.
2. a[j] should be as small as pissible.

sort array and take the difference of last half - first half. (asending sorted array.)

To minimize diff
1. sorted array
take alternate element sumOf(odd index) - sumOf(even index)
*/

int main(){
    int n;cin >> n;
    vector<int> a(n);
    rep(i,0,n)
    cin >> a[i];

    sort(a.begin(),a.end());
    long long mn = 0 ;
    long long mx = 0 ;

    rep(i,0,n/2){
        mx  += (a[i+n/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }

    cout << mn << " " << mx << endl;
    return 0;
}