#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
    // for(auto i:s){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "Size of set is " << s.size() <<endl;

    // for(auto i  : s)
    // cout <<"Upper and lower bound of " << i<< " is " << *s.upper_bound(i) << " and " << *s.lower_bound(i) <<endl;

    // cout << "erase elements" <<endl;

    // s.erase(2);

    // Multiset
    // multiset<int> ms;
    // ms.insert(1);
    // ms.insert(2);
    // ms.insert(3);
    // ms.insert(4);
    // ms.insert(3);
    // for(auto i:ms){
    //     cout << i << " ";
    // }
    // cout << endl;

    // ms.erase(3);

    // for(auto i:ms){
    //     cout << i << " ";
    // }
    // cout << endl;
    // if we erase any element every occurance of element get deleted.

    // Unordered set
    unordered_set<int> uos;
    uos.insert(1);
    uos.insert(2);
    uos.insert(3);
    uos.insert(4);
    uos.insert(3);
    uos.insert(3);
    for(auto i:uos){
        cout << i << " ";
    }
    cout << endl;
    uos.erase(3);
    for(auto i:uos){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}