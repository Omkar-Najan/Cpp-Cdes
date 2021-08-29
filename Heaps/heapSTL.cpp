#include<iostream>
#include <vector>
#include<queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>> pq; // maxheap
    pq.push(2);
    pq.push(3);
    pq.push(5);
    pq.push(1);


    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;


    priority_queue<int , vector<int> , greater<int>> pqm; //Minheap.
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    pqm.push(4);
    pqm.push(5);

    cout << pqm.top() << endl;
}