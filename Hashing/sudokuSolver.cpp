#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i =a;i<b;i++)

/*
pseudocode
1. start from 0,0 and rach to 8,8
2. try out all valid combinations
3. ans = false at x,y
4. if ans = already filled, move on to next block
5. else, for(number 0 to 9)
    if you can place number at x,y
        ans = ans or place number at x,y and move on.

 */

void helper(int r , int c,vector<vector<char>> &a , map<pair<int,int> , map<int,int>> & mp, vector<map<int,int>> row ,vector<map<int,int>> col){

    if(r >= 9){
        for(auto it:a)
        {
            for(auto i : it){
            cout << i <<" ";
            }
            cout << endl;
        }
        cout << endl;

        return ;
    }else{
    if(c== 9){
        helper(r+1 , 0,a,mp,row,col);
        return;
    }

    if(a[r][c] != '.'){
        // not empty
        helper(r,c+1,a,mp,row,col);
        return;
    }

    for(int i = 1;i<=9;i++){
        int rw = r/3 , cl = c/3;
        if(!mp[{rw,cl}][i] && !row[r][i] && !col[c][i]){
            mp[{rw,cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] =1;
            a[r][c] = i + '0';
            helper(r ,c+1 ,a , mp,row,col);
            mp[{rw,cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] =0;
            a[r][c] = '.';
        }
    }

    }
    
    return;
}


void solveSoduku(vector<vector<char>>&a){
    map<pair<int,int> ,map<int,int>>mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);


    for(int i =0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(a[i][j] != '.'){
                mp[{i/3 , j/3}][a[i][j] -'0'] = 1;
                row[i][a[i][j]] =1;
                col[j][a[i][j]] =1;
            }
        }
    }
    helper(0,0,a,mp,row,col);
    return;

}

int main(){
    vector<vector<char>> soduku = {

        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };

    solveSoduku(soduku);

    return 0;
}