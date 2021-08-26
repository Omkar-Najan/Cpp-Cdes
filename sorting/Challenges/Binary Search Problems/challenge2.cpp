/*
Allocate minimum pages
n = number of pages in different books asending order
m = number of students
all books must have divided amoung m student consecutively. allocate the pages
in such a way that maximum pages allocated to a student is minimum.
*/
#include<iostream>
#include <algorithm>
using namespace std;

/*
Apply binary search for min and max possible values of 'max' pages.

Checking feasibility:
    assign pages to each student in a sequential manner, while current number of 
    allocate pages don't exceed the value set by binary search.

    if durinng allocation the number of students don't exceed the limits of m then sol is feasible. else it isn't.
*/
bool isPossible(int arr[] , int n , int m,int min ){
    int studentsRequired = 1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        
        if(arr[i] > min){
            return false;
        }
        
        if(sum + arr[i] > min){
            studentsRequired++;
            sum = arr[i];
            if(studentsRequired > m){
                return false;
            }
        }else{
            sum += arr[i];
        }
    }
    return true;
}
int allocateMinimum(int arr[] , int n, int m){
    int sum = 0;
    if(n<m){
        return -1;
    }

    for(int i = 0;i<n;i++){
        sum = sum + arr[i];
    }

    int start = 0,end = sum , ans = INT_MAX;
    while(start <= end){
        int mid = (start + end)/2;
        if(isPossible(arr,n,m,mid)){
            ans= min(ans , mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;

    cout << allocateMinimum(arr,n,m);

}