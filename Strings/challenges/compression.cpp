/*
PS: Given a string s, your task is to remove the repeating 
consecutive characters.

Approach: Create an answer string and iterate in the string from i=1 and check if it
is equal to the previous character. Two cases arise
1. s[i] = s[i-1] - then do not push_back the ith character to the answer string.
2. s[i] != s[i-1] - then push_back the ith character to the answer string.
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(){
    string s = "assasssdddffdsgghhtnbsskoonnsssesssa";
    int n = s.size();

    char ans[n];
    ans[0] = s[0];
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans[cnt] = s[i], cnt++;
        }
    }
    ans[cnt] = '\0';
    cout << ans<< endl;
    return 0;
}