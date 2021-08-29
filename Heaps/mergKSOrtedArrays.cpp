#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pii pair<int,int>
/*
input : k sorted arrays. 
output : sorted merged array.

Approach:
    brute force: take 2 arraya and merg them repeat this process until we are left with one array.

    OPtimize approach:
    using heaps.
    1. create a mini heap of pairs.
        pair( value , array number.)
    2. Insert {first element, array Number} of all sorted array into MinHeap.
    3. Main Idea: we will pop element from the MinHeap and store into the answer Array. Insert next element of sorted array MinHeap.

    4. keep track of index of array. 

*/

int main(){
    int k ; 
    cin >> k;

    vector<vector <int>> a(k) ;

    for(int i = 0;i<k;i++){
        int size;
        cin >> size;

        a[i] = vector<int> (size);
        for(int j = 0;j<size;j++){
            cin >> a[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue<pii , vector<pii>,greater<pii>> pq;
    for(int i = 0;i<k;i++){
        pq.push({a[i][0] , i});   
    }

    vector<int> ans;
    while(!pq.empty()){
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second]+1 < a[x.second].size()){
            pq.push({a[x.second][idx[x.second]+1] , x.second});
        }
        idx[x.second] += 1;
    }

    for(int i = 0;i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}