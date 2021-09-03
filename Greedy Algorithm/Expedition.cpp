#include <bits/stdc++.h>
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
A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. 
The truck now leaks one unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. 
On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).
The jungle is a dangerous place for humans and is especially dangerous for cows. 
Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. 
Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. 
The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).
Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

Input
The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:

Line 1: A single integer, N
Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
Line N+2: Two space-separated integers, L and P
Output
For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.


example:
input:
1
4
4 4
5 2
11 5
15 10
25 10

output:
2
*/

int main(){
    int t;  // test cases
    cin >> t;   
    while(t--){
        int n;
        cin >> n;
        vii a(n);
        rep(i,0,n){
            cin >> a[i].ff >> a[i].ss; // taking input of distance from towm and capacity of pump.
        }
        int l,p;
        cin >> l >> p;

        rep(i,0,n){
            a[i].ff = l-a[i].ff; // to calculate distance form truck.
        }

        sort(a.begin(),a.end());
        int ans =0;
        int curr = p; // current fule in tank

        priority_queue<int,vector<int> > pq;
        bool flag =  0;
        rep(i,0,n){
            if(curr >= l){
                break;
            }

            while(curr < a[i].ff){
                if(pq.empty()){
                    flag  =   1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if(flag==1){
                break;
            }

            pq.push(a[i].ss);

        }

        if(flag){
            cout << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr <l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if(curr < l){
            cout << "-1" << endl;
            continue;
        }

        cout << ans << endl;
    }
    return 0;
}