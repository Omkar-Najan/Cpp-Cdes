/*
Subarray of size k with palindromic concatenation

for a given array and an integer k, check if any subarray of size k exists in 
the array such that concatenation of elements form a palindrome.

approach 1 brute force O(n^3)

approach 2 : sliding window protocol O(n^2)
    1. store concatenation of initial k elements 
    2. iterate over the array and start deleting elements from the start and adding element from end.
    3. at each step check if concatenation is a palindrome.


*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


bool isPalindrome(int  num){
    int temp = num , n = 0;
    while(temp > 0){
        n = n*10 + temp%10;
        temp = temp/10;
    }    

    return (num == n);
}

int findPalindromicSubarray(vector<int> arr, int k){
    int num= 0;
    for(int i = 0;i<k;i++){
        num = num*10+arr[i];
    }
    if(isPalindrome(num)){
        return 0;
    }

    for(int j = k;j<arr.size();j++){
        num = (num % (int)pow(10,k-1)) * 10 + arr[j];

        if(isPalindrome(num)){
            return j-k+1;
        }
    }

    return -1;
}



int main(){
    vector<int> arr = {2,3,5,1,1,5};
    int k = 4;

    int ans = findPalindromicSubarray(arr,k);
    if(ans == -1){
        cout << "Subarray not found" << endl;
    }else{
        for(int i = ans;i<ans+k;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}