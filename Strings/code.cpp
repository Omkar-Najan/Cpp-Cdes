#include <iostream>
#include <string>
// to sort string use algorithm header file.
#include <algorithm>
using namespace std;

int main(){
    // string name;
    // getline(cin ,name);
    // cout << name << endl;
    // // append O(N) -> N = size of new string.
    // string s1 = "Fam" , s2 = "Ily";
    // s1.append(s2); // s1 = s1 + s2;
    // cout << s1 << endl;

    // // assign() -> assignes new value to string. (=)
    // string s = "Omkar";
    // s.assign("Najan");  // s = "Najan"
    // cout << s <<endl;

    // at() -> returns character at pertiular position ([i]); O(1)
    // string s = "Omkar";
    // cout << s.at(3) << endl;  // cout << s[3] << endl;

    // Begin -> First character of string. O(1)
    // clear -> erases all contents of string and assign empty string. O(1).
    // compare -> compares two strings and returns value 
    // string s1 = "abc", s2 = "xyz";
    // cout << s2.compare(s1) << endl; 
    //  result : +ve -> s2 > s1
    //          -ve -> s2 < s1
    //          0   -> s2 = s1.

    // c_str() -> Convert string into C-style string (null terminating string) and returns the pointer to C-style string.
    // Complexity is O(1).

    // empty() -> Returns boolean value, True if string is empty. 
    // end() -> returns an iterator pointing to a position which is next to the last character.O(1)

    // erase() -> deletes substrinng of string. O(n) n-> length of new string. 
    string s = "OmkarNajan" ;
    s.erase(3,3);
    cout << s << endl;
   
    // find() -> searches and returns the first ocurrences of the parameer of string. its O(n) where n is size of string.  
    cout << s.find("Om") << endl;
    
    // insert() -> inserts additiona character into string at erticular location. 
    cout << s.insert(3,"arN") << endl;

    // length() / size() -> Gives the length of string. 
    // resize() -> returns new length that can be less than or greater than of current length.
    s.resize(5);
    cout <<  s<< endl;

    // substr() -> returns string which is copy of substring. 
    // parameters (start , end)
    cout << s.substr(3,4) << endl;

    // stoi() -> string converted into integer point
    string numerical = "123";
    int x = stoi(numerical);
    cout << x-22 << endl;

    // to_string(int) -> convert into string.
    cout << to_string(x) << endl;

    // sorting the string
    // use <algorithm> header file
    sort(s.begin() , s.end());
    cout<< s << endl; 
    return 0;
}
