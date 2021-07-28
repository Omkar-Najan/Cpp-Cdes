#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(int i = 0;i<v.size();i++){
        // cout << v[i] << endl;
    } // 1 2 3 4
    
    // iterator.
    // iterator is pointer
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end();it++){
        // cout << *it << endl;
    }// 1 2 3 4 
    
    for(auto element:v){
        // cout << element << " ";
    }// element != iterator 
    cout << endl;
    
    v.pop_back(); // void function does not returns last element.
    for(auto element:v){
        // cout << element << " ";
    }// 1 2 3

    vector<int> v2 (3,50); // 3 elements and 50 50 50

    // swap vectors. 

    swap(v,v2);
    for( auto ele:v2){
        cout << ele<< " ";
    }

    for( auto ele:v){
        cout << ele<< " ";
    }

    // sort operator
    sort(v.begin() , v.end());

    pair <int, char> p;
    
    return 0;
}