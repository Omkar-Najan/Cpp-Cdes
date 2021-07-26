#include<iostream>
using namespace std;

void primeinrange(int n,int m){
    int prime[m+1] = {0};
    for(int i =2;i <=m;i++){
        if(prime[i] ==0){
            for(int j = i*i;j<=m;j+=i){
                prime[j] = 1;
            }
        }
    }

    for(int i= n;i<=m;i++){
        if(prime[i] == 0){
            cout << i << endl;
        }
    }
}


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    primeinrange(n,m);
    return 0;
}