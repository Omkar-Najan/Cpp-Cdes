#include<iostream>
using namespace std;

// problem :
// Given a squre matrix A and its number of rows (or columns) N, return the transpose of A.
// int mainTranspose of matrx is the matrix is the matrix filpped over its main diagonal switching the row and columns indices of the matrix.
int main(){
    int n;
    cin >> n ;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    // transpose
    for(int i = 0; i < n ; i++){
        for(int j = i;j<n;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    // print matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}