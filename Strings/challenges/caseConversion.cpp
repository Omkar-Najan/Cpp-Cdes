#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s = "oihfodfnihbfeikcvbediuvid";
    sort(s.begin() , s.end());

    // to upper case 
    transform(s.begin() , s.end(), s.begin() ,:: toupper);
    cout << s << endl;

    // to lower case
    transform(s.begin() , s.end(), s.begin() ,:: tolower);
    cout << s << endl;

    //  approach 2
    // to upper case
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' || s[i] <= 'z'){
            s[i] -= 32;
        }
    }
    cout << s << endl;

    //  to lower case
    for(int i = 0; i < s.size(); i++){
    if(s[i] >= 'A' || s[i] <= 'Z'){
            s[i] += 32;
        }
    }
    cout << s << endl;

    // sort srting in descending order
    sort(s.begin() , s.end() , greater<int>());
    cout << s << endl;
    return 0;
}