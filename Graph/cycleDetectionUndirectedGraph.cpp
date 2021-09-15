#include<iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
/**
 * cycle detection in Undirected Graph
 * 1. keep traversing Graph
 * 2. if we found an edge pointing to already visited node except the parent node, a cycle is found.
*/
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int ,int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i,a,b) for(int i =a ;i<b;i++)


bool iscycle(int src,vector<vector <int>> &adj,vector<bool>&visited ,int parent){
    visited[src] = true;
    for(auto i:adj[src]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] && iscycle(i,adj,visited,src)){
                return true;
            }
            
        }
    }

    return false;
}




int main(){
    int n , m ; 
    cin >> n >> m;
    int x , y;
    vector<vector<int>> adj(n);

    rep(i,0,m){
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
        cout << i << " ";
    }
    return 0 ;

    cout <<   "code is here 0" ;
    bool cycle = false;
    vector<bool> visited(n , false);
    cout <<   "code is here 1" ;
    rep(i,0,n){
        if(!visited[i] && iscycle(i,adj,visited , -1)){
            cycle = true;
        }
    }

    if(cycle){
        cout<< "Cycle is present";
    }else{
        cout << "Cycle is not present";
    }
    cout << "code is here";
    return 0;
}