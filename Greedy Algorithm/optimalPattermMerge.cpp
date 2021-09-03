#include <iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Optimal Merge Pattern

Problem : n files with their computation time in an array
operation : choose/take any two files add their computation times and 
            append it to the list of computation times.
            cost = {sum of computation time}

            do this untill we have only one file in array.
            find min cost .

example : 5 2 4 7

Approach 
1. push all elements in minheap
2. take top 2 elements one by one and add the cost to answer. Push merged file to minheap.
3. when single element remains output the cost.

*/

// macros defination
#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i,a,b) for(int i = a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main(){
    int n ;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
    }

    priority_queue<int , vector<int> , greater<int> > minHeap;

    rep(i,0,n){
        minHeap.push(a[i]);
    }

    int ans = 0;

    while(minHeap.size() > 1){
        int e1 = minHeap.top();
        minHeap.pop();
        int e2 = minHeap.top();
        minHeap.pop();

        ans += e1 + e2;

        minHeap.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}