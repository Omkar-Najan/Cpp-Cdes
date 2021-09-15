#include<iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int ,int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i =a ;i<b;i++)

const int N = 1e5+2 , MOD = 1e9+7;

vi adj[N];

int main(){
    
    int n,m;
    cin >> n >> m;
    
    int cnt = 0;
    int u , v;
    
    vector<int> indeg(n,0);

    for(int i =0;i<m;i++){
        cin  >> u >> v;
        // u --> v
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    queue<int> pq;
    for(int i = 0 ; i < n ; i ++) {
        if(indeg[i] == 0){
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for(auto it : adj[x]){
            indeg[it]--;
            if(indeg[it] == 0){
                pq.push(it);
            }

        }
    }
    
}