/*
Given a string s of latin characters, your task is to output the character which has
maximum frequency
*/

// Approach:
// Maintain frequency of elements in a separate array and iterate over the array and
// find the maximum frequency character

#include <iostream>
#include<string>
#include <algorithm>

using namespace std;

int main(){
    string s = "lkdnviofeshgldknvlihsgoehjgvlkdfhbir";
    int a[26];
    for(int i = 0;i<26;i++){
        a[i] = 0;
    }
    for(int i=0;i<s.size();i++){
        a[s[i] - 'a']++;
    }
    char ans;
    int maxfreq = -1;
    for(int i=0;i<26;i++){
        if(maxfreq < a[i]){
            maxfreq = a[i];
            ans = 'a' + i;
        }
    }
    cout << maxfreq << " " << ans << endl;
}