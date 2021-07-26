#include<iostream>
using namespace std;
/*
while(num != 1):
    keep dividing it with its smalllest prime factor. The smallest prime factor
    is pre-calculated using a slightly modified prime seive. 
    since we start with 2 and go on mark first multiple as spf.
    preprocessing for seive: O(n log n)
    time : O(logn)
    space : O(n)

*/

void primefactor(int n){
    int spf[100] = {0};
    for(int i =2;i<=n;i++){
        spf[i] = i;
    }

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j = i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1){
        cout << spf[n] << " ";
        n = n/spf[n];
    }
}


int main(){

    int n;
    cin >> n;
    primefactor(n);
    return 0;

}