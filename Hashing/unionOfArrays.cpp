#include<iostream>
#include<unordered_set>
using namespace std;

void unionOfArray(int a1[] , int a2[],int n1,int n2){
    unordered_set<int> s1;
    for(int i = 0;i<n1;i++){
        s1.insert(a1[i]);
    }
    for(int i = 0;i<n2;i++){
        s1.insert(a2[i]);
    }

    cout<< s1.size();

}

int main(){
    int a1[] = {1,2,3,4,4,3,1,2,3};
    int a2[] = {5,4,3,2,1,2,3,4,5};

    unionOfArray(a1, a2 , 9,9);
    return 0;
}