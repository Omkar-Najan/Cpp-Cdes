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


// representation of graphs

int main(){
    int n,m;
    cin >> n >> m;  // take input of number of nodes and edges from user.

    vvi adjm(n+1 , vi(n+1 , 0)); // adjcency matrix

    int x,y; // declaring variables for taking input.
    
    rep(i,0,m){
        cin >> x >> y;

        adjm[x][y] = 1;    // as gaph is undirected values at x y and y x should be 1
        adjm[y][x] = 1;
    }
    
    cout << "Adj matrix is given by "<< endl;
    rep(i,1,n+1){   // printing of matrix
        rep(j,1,n+1){
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    if(adjm[3][7] == 1)   // to check if edge exists between a and b check value at adjm[a][b]
        cout << "There is an edge between 3 and 7";
    else
        cout << "No edge";
    

     cout << endl;
     cout << endl;
     cout << endl;
    //  adjacency list

    cin >> n >> m;

    rep(i,0,m){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout << "Adjacency list of above graph is given by" << endl;

    rep(i,1,n+1){
        cout << i << " -> ";
        for(int x :adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;

}