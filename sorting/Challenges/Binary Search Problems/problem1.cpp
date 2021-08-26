#include<iostream>
#include<algorithm>
using namespace std;

/*

Given an arrzy with n elements that represent n position
along a straight line. Find k elements such that minimum distance between 
any 2 elements is the max possible

*/
/*

approach 1 :
find all possible subset of size k and compare the minimum distance between all of them

approach 2 :
1. sort array for binary search technique. 
2. pick middle element as result and check for frasibility.
3. if feasible, search right half of array with largest minimum distance
4. else, search left half of array.

*/

bool isfeasible(int mid , int arr[] , int n ,int k){
    int pos  = arr[0] , element = 1;
    for(int i = 1;i<n;i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            element ++;
            cout << arr[i] <<" ";
            if(element==k){
                return true;
            }
        }    
    }
    return false;
}


int largestMinDist(int arr[] , int n, int k){
    sort(arr , arr+n);

    int res = -1;
    int left = arr[0];
    int right = arr[n-1];
    while(left < right){
        int mid = (left + right)/2;
        if(isfeasible(mid , arr, n,k)){
            res = max(res,mid);
            left = mid + 1;

        }else{
            right = mid;

        }
    }
    return res;
}


int main(){

    int arr[] = {1,2,8,4,10,12};
    int n = 6;
    int k = 3;
    
    cout << "Largest min distance is : " << largestMinDist(arr , n,k);

}


