#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
IMP
smallest subsequence with sum k.
give a smallest subsequence with sum K.

subarray : contunious 
subsequence : not necessary continuous, but order should remain same.

return every subsequence with sum >= k.

Approach:
    maxheap and insert all element. 
    keep poping element and then add it to sum. if sum>= k output count. 

*/


int main(){
    int n,k;
    cin >>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    priority_queue<int , vector<int>> pq;

    for(int i =0;i<n;i++){
        pq.push(a[i]);
    }

    int sum = 0;int cnt = 0;
    while (!pq.empty())
    {
        sum +=  pq.top();
        cnt++;
        pq.pop();

        if(sum>=k){
            break;
        }
    }
    
    if(sum < k){
        cout << -1 << endl;
    }else{
        cout << cnt << endl;
    }
    return 0;
}