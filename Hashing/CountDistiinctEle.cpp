#include<iostream>
#include<unordered_set>
using namespace std;

int countDistEle(int arr[] , int n){
    unordered_set<int> set;

    for(int i = 0;i<n;i++){
        set.insert(arr[i]);
    }
    return set.size();
}

int main(){
    int a[]= {1,2,3,3,4,4,5,6,5,4,3,2,1,2,3,4,5};
    int n = 17;
    cout << countDistEle(a,n);
}
