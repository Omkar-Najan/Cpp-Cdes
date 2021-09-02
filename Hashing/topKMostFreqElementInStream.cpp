#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
We have to output elements in decreasing order frequency till we reach 
K+1 th distinct elenents.
*/
/*
Hashing 
1. create a map
2. while traversing keep track of elements and when we find (K+1)th without element = break.
3. output the element and frequency using map.
*/
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int , int>>
#define rep(i,a,b) for(int i= a;i<b;i++)
#define ff first
#define ss second

int main(){
    int n,k;
    cin >> n>>k;

    vi a(n);

    rep(i,0,n){
        cin >> a[i];
    }

    map<int,int>  freq;
    rep(i,0,n){
        int presize = freq.size();
        if(freq[a[i]] == 0 && presize == k){
            break;
        }
        freq[a[i]]++;
    }

    vector<pair<int,int>> ans;

    map<int ,int> :: iterator it;
    for(it = freq.begin(); it!= freq.end();it++){
        if(it->ss != 0){
            pii p;
            p.ff = it->ss;
            p.ss = it->ff;
            ans.push_back(p);
        }
         
    }
    sort(ans.begin(),ans.end(),greater<pii>());

    vii :: iterator ite;

    for(ite = ans.begin();ite!= ans.end();ite++){
        cout << ite->ss << " " << ite->ff << endl;
    }

}