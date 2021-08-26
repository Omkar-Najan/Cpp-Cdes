#include<iostream>
#include<cmath>
using namespace std;
/*
Trick : 
    convert the given array into binary array into a binary array with values 0 and 1.

Approach : O(n*sqrt(n))
    traverse array if number at index i is perfect number then replace value at ith index with 0 or 1.

    1. initilize a variable to store sum of divisiors.
    2. traverse every number less than arr[i] and add it to sum if it is divisior of arr[i]
    3. if sum of all divisiors is equal to arr[i], then only number is perfect number.
*/

int maxSum(int arr[] , int n, int k){
    if(n < k){
        return -1;
    }

    int res = 0;
    for(int i = 0; i<k;i++){
        res += arr[i];
    }
    int sum = res;
    for(int i = k;i<n;i++){
        sum += arr[i] - arr[i-k];
        res = max(res,sum);
    }

    return res;
}

bool isPerfect(int n){
    int sum = 1;
    for(int i = 2;i<sqrt(n);i++){
        if(n%i == 0){
            if(i == n/i){
                sum += i;
            }else{
                sum += i + n/i;
            }
        }
    }

    if(sum == n && n!= 1){
        return true;
    }
    return false;
}

int maxNumOfPerfects(int arr[], int n,int k){
    
    for(int i = 0 ;i<n;i++){
        if(isPerfect(arr[i])){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }
    for(int i = 0 ;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxSum(arr,n , k);
}


int main(){

    int arr[] = {28,2,3,6,496,99,8128,24};
    int n = 8;
    int k = 4;
    cout << maxNumOfPerfects(arr,n,k);
    return 0;
}






