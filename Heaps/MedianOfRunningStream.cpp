#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
Find the median form continuous stream of element.
IMP

*/

/*
Approach: 
    brute force.
        after each input, sort array {NlogN}and then quote median. n^2Log(n).


    Optimal Approach
        1. keep ont MaxHeap and one MinHeap.
        2. Partition array into two parts.

        if sizes of MaxHeap and MinHeap are not Equal then =  top of larger size heap.
        if size of heaps are equal then give the mean of top of both arrays.
*/

priority_queue <int , vector<int>> pqmax;
priority_queue <int , vector<int> , greater<int>> pqmin;

void insert(int n){
    if(pqmax.size() == pqmin.size()){
        if(pqmax.size() == 0){
            pqmax.push(n);
            return ;
        }

        if(pqmax.top() > n){
            pqmax.push(n);
        }else{
            pqmin.push(n);
        }
    }else{
        // 2 cases ;
        if(pqmax.size() > pqmin.size()){
            if(n >= pqmax.top()){
                pqmin.push(n);
            }else{
                int temp = pqmax.top();
                pqmin.push(temp);
                pqmax.push(n);
            }
        }else{
            if(n <= pqmin.top()){
                pqmax.push(n);
            }else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(n);

            }
        }
    }
}


double findMedian(){
    if(pqmin.size() == pqmax.size()){
        return (pqmin.top() + pqmax.top())/2.0;
    }
    else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }else{
        return pqmin.top();
    }
}

int main(){

    insert(10);
    cout << findMedian() << endl;

    insert(11);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    insert(20);
    cout << findMedian() << endl;

    return 0;
}