#include<iostream>
#include<vector>
using namespace std;

/*
for a given array and integer k, check if subarray of size k exists in array such that elements in subarray form 
a number divisible by 3.
*/

/*
approach 1 : compute numbers formed by all possible subarray of K. check for divisibility for 3. O(n^2)

approach 2:  O(n)
    1. sum intial k element from array.
    2. use sliding window tech and one by one, start subtracting elements from the end and adding from end.
    3. at each step check if sum divisible by 3 or not. if it is print the elements.
*/

void computeNumberFromSubarray(vector<int> arr,int k){
    pair<int , int>ans;
    int sum =0;


    for(int i = 0;i<k;i++){
        sum += arr[i];
    }

    bool found = false;
    if(sum % 3 == 0){
        ans = make_pair(0,k-1);
        found = true;
    }

    for(int  j = k;j < arr.size() ; j++){
        if(found){
            break;
        }
        
        sum =  sum + arr[j] - arr[j-k];
        if(sum%3 == 0){
            ans = make_pair(j-k+1 , j);
            found = true;
        }
    }
    
    if(!found){
        ans = make_pair(-1,0);
    }
    
    if(ans.first == -1){
        cout << "No such subarray exists" << endl;
    }
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}




int main(){

    vector<int> arr  = {84,23,45,12,56,82};
    int k = 3;
    computeNumberFromSubarray(arr,k);
    return 0;
}