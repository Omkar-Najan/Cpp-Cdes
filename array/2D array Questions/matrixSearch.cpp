#include<iostream>
using namespace std;

// Given an n*m matrix write an algorithm to find that the given value exists in the matrix or not
// integers in each row are stored in ascending from left to right. 
// integers in each column are stored in ascending from top to bottom.
// each row and column are sorted.
int main(){
    int n , m;
    cin >> n>>m ;
    int target;cin >> target;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    int r = 0,c = m-1;
    bool found = false;
    while((r < n) and (c >= 0)){
        if (arr[r][c] == target){
            found = true;
        }
        if(arr[r][c] > target){
            c--;
        }else{
            r++;
        }
    }
    if(found){
        cout << "Element found";
    }
    else{
        cout << "element not found" ;
    }
    return 0;
}