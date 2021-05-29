#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    // inverted pyramid
    for(int i = n; i>=1; i--){
        for (int j = 1;j<=i ;j++ ){
            cout <<'*';
        }
        cout<<endl;
    }

    // half pyramid
    for(int i=1;i <=n;i++){
        for(int j =1;j<=n;j++){
            if(j <= n-i){
                cout<<" ";
            }else{
            cout<<"*";
            }
        }
        cout<<endl;
    }

    // half pyramid using numbers
    for( int i =1 ; i <=n ; i++){
        for (int j = 1 ; j <=i;j++){
            cout << i;
        }
        cout << endl;
    }

    // floyed's triangle 
    int num = 1;
    for( int i =1 ; i <=n ; i++){
        for (int j = 1 ; j <=i;j++){
            cout << num;
            num++;
        }
        cout << endl;
    }

    // butterfly patern 
    // rows = n , col = 2n . 
    for ( int i =1 ; i <=n ; i++){
        for (int j =1 ; j<=i;j++){
            cout<<"*";
        }
        int space  = 2*n-2*i;
        for(int j =1; j<= space; j++){
            cout<<" ";
        }
                for (int j =1 ; j<=i;j++){
            cout<<"*";
        }
        cout << endl;
    }
    for ( int i = n  ; i >= 1 ; i--){
        for (int j =1 ; j<=i;j++){
            cout<<"*";
        }
        int space  = 2*n-2*i;
        for(int j =1; j<= space; j++){
            cout<<" ";
        }
                for (int j =1 ; j<=i;j++){
            cout<<"*";
        }
        cout << endl;
    }
    return 0;
}