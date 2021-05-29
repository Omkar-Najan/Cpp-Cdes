#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    // numerical patterns
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){
            cout<<j<<" ";
        }
        cout << endl;
    }
    // 0 1 pattern 
    cout << endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           if((i+j)%2 == 0){
               cout<< 1;
           }else{
               cout << 0;
           }
        }
        cout << endl;
    }

    cout << endl;
    // rhombus pattern 
    // rows 1 to n 
    // columns spaces : n to n- row 
    // col * 1 to n .

    for ( int i = 1 ; i<= n;i++){
        for(int j = 1 ; j <= n-i; j++){
            cout << " ";
        }
        for(int j = 1 ; j <=n ; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    // number pattern
    // columns : space (n-i) 
    // col : 1 to row number
    for(int i = 1 ; i<=n;i++){
        for(int j = 1 ; j<=n-i;j++){
            cout << " ";
        }
        for(int j = 1 ; j <= i ; j++){
            cout << j << " ";
        }
        cout<< endl;
    }

    // Palyndromic pattern 
    //  rows : n (1 to n)
    // col : space (1 to n-row number)
    // col : numbers row number to 1 and then till row number.

    for(int i =1 ; i<=n;i++){
        int j;
        for(j =1 ; j<= n-i ; j++){
            cout<<"  ";
        }
        int k = i;
        for(;j<=n;j++){
            cout<<k--<<" ";
        }
        k = 2;
        for(;j<=n+i-1;j++){
            cout << k++<<" ";
        }
        cout << endl;
    }
    // inverted pyramid
    for(int i =1 ; i<=n;i++){
        int j;
        for(j =1 ; j<= n-i ; j++){
            cout<<"  ";
        }
        int k = i;
        for(;j<=n;j++){
            cout<<"*"<<" ";
        }
        k = 2;
        for(;j<=n+i-1;j++){
            cout <<"*"<<" ";
        }
        cout << endl;
    }
    for(int i = n ; i>=1;i--){
        int j;
        for(j =1 ; j<= n-i ; j++){
            cout<<"  ";
        }
        int k = i;
        for(;j<=n;j++){
            cout<<"*"<<" ";
        }
        k = 2;
        for(;j<=n+i-1;j++){
            cout <<"*"<<" ";
        }
        cout << endl;
    }
   // zigzag patern 
   // n = 9 , rows : 3
   //   *    *
   //  *  * *  *
   // *    *    *
    for(int i =1; i <=3 ;i++){
        for(int j =1;j<=n ; j++){
            if(((i+j)%4 ==0) || (i ==2 && j%4 ==0)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout << endl;
    }


    return 0;
}