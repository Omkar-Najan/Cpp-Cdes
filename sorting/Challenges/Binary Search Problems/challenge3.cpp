/*
Painters partitin problem
n - length of different boards
m - painters available

a painter paints 1 unit of board in 1 unit of time and each painter will
paint consewutive boards. find the minimum time that wil be required to paint all boards.
*/

/*
boards = {10 20 30 40}
painters = 2
possible partitions = 
10   20 30 40    --------> 90
10 20     30 40  --------> 70
10 20 30     40  --------> 60

*/
#include<iostream>
#include <algorithm>
using namespace std;
/*
apply binary search for minimum and maximum possible values of 'min' length of boards.
check feasibility  of this choosen value.

to check feasibility:
    assign boards to each painter in a sequential manner while the current length of assignd boards don't exceed 
    the value set by binary search

    if during allocation number of painters dont exceed the limit of m, then sol is feasibile.
*/


int findFeasible(int boards[] , int n, int limit){
    int sum = 0 ,painters = 1;
    for(int i =0;i<n;i++){
        sum += boards[i];
        if(sum > limit){
          sum = boards[i];
          painters++;  
        }
    }
    return painters;
}


int paintersPartition(int boards[] , int n,int m){
    int totalLength = 0 , maxLength = 0;
    for(int i = 0;i<n;i++){
        maxLength = max(maxLength,boards[i]);
        totalLength += boards[i];
    }
    int low = maxLength , high = totalLength;
    while(low < high){
        int mid = (low + high)/2;
        int painters = findFeasible(boards , n, mid);
        if(painters <= m){
            high = mid;
        }else{
            low = mid +1;
        }
    }
    return low;
}


int main(){
    int boards[] = {10,20,30,40};
    int n = 4;
    int m =2;
    cout << paintersPartition(boards , n , m);
}