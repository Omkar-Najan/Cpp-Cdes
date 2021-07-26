#include<iostream>
#include<string>
using namespace std;
/*
Time Complexity: O(N2)
Space Complexity: O(N2)
Time complexity will be O(N2) 
because s.substr(i) takes O(N) times and it is called
O(N) times.
Space complexity will be O(N2) because s.substr(i) gives a string of O(N) size and it
is called O(N) times
*/

string duplicates(string s){
    if(s.length() ==0){
        return "";
    }
    char ch =s[0];
    string ans  = duplicates(s.substr(1));

    if (ch == ans[0]){
        return ans;
    }
    return (ch+ans);
}



int main(){
    cout << duplicates("aaaabbbbeecssdd");
    return 0;
}
