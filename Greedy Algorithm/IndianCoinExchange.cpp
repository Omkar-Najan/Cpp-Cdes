#include "bits/stdc++.h"
using namespace std;

/*
Indian coin exchange problem.
1 2 5 10 20 50 100 200 500 2000
*/

// Visualization of code : https://pythontutor.com/cpp.html#code=%23include%20%22bits/stdc%2B%2B.h%22%0Ausing%20namespace%20std%3B%0A%0A/*%0AIndian%20coin%20exchange%20problem.%0A1%202%205%2010%2020%2050%20100%20200%20500%202000%0A*/%0A%0A//%20macros%20defination%0A%23define%20vi%20vector%3Cint%3E%0A%23define%20pii%20pair%3Cint%20,%20int%3E%0A%23define%20vii%20vector%3Cpii%3E%0A%23define%20rep%28i,a,b%29%20for%28int%20i%20%3D%20a%3Bi%3Cb%3Bi%2B%2B%29%0A%23define%20ff%20first%0A%23define%20ss%20second%0A%23define%20setBits%28x%29%20builtin_popcount%28x%29%0A%0A%0Aint%20main%28%29%7B%0A%20%20%20%20int%20n%3D%2010%3B%0A%20%20%20%20//%20cin%20%3E%3E%20n%3B%0A%20%20%20%20vi%20a%20%3D%20%7B%201%20,%202,5,10,20,50,100,200,500,2000%7D%3B%0A%0A%20%20%20%20//%20rep%28i,0,n%29%7B%0A%20%20%20%20//%20%20%20%20%20cin%20%3E%3E%20a%5Bi%5D%3B%0A%20%20%20%20//%20%7D%0A%0A%20%20%20%20int%20x%20%3D%2054%3B%20%0A%20%20%20%20//%20cin%20%3E%3E%20x%3B%0A%0A%20%20%20%20sort%28a.begin%28%29,a.end%28%29,greater%3Cint%3E%28%29%29%3B%0A%0A%20%20%20%20int%20ans%20%3D%200%3B%0A%0A%20%20%20%20for%28int%20i%20%3D%200%3Bi%3Cn%3Bi%2B%2B%29%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%22value%20of%20a%5Bi%5D%20at%20i%20%3D%20%20%22%3C%3C%20i%3C%3C%20%22%20is%20%22%20%3C%3C%20a%5Bi%5D%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20ans%20%2B%3D%20x/a%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%22value%20of%20ans%20at%20i%20%3D%20%20%22%3C%3C%20i%3C%3C%20%22%20is%20%22%20%3C%3C%20ans%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20x%20-%3D%20x/a%5Bi%5D%20*%20a%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%22value%20of%20x%20at%20i%20%3D%20%20%22%3C%3C%20i%3C%3C%20%22%20is%20%22%20%3C%3C%20x%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%20%20%20%20cout%20%3C%3C%20%22%5Cn%5Cn%22%20%3B%0A%20%20%20%20cout%20%3C%3C%20ans%3B%0A%20%20%20%20return%200%3B%0A%7D&curInstr=70&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D


// macros defination
#define vi vector<int>
#define pii pair<int , int>
#define vii vector<pii>
#define rep(i,a,b) for(int i = a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


int main(){
    int n;
    cin >> n;
    vi a(n);

    rep(i,0,n){
        cin >> a[i];
    }

    int x; 
    cin >> x;

    sort(a.begin(),a.end(),greater<int>());

    int ans = 0;

    for(int i = 0;i<n;i++){
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }

    cout << ans;
    return 0;
}