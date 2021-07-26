/*
calculate number of paths possible from starting to end point in game
Idea:
We have 6 ways to go forward (1,2,3,4,5,6).
At the starting point s,
Current answer = countPath(s+1,e) + countPath(s+2,e) + countPath(s+3,e) +
countPath(s+4,e) + countPath(s+5,e) + countPath(s+6,e)
Time Complexity: O(2n)
Space Complexity: O(2n)

*/

#include <iostream>
#include <string>
using namespace std;

int countPath(int s , int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int result = 0;
    for(int i = 1; i<=6;i++){
        result = result + countPath(s+i,e);
    }
    return result;
}

int main(){
    cout << countPath(0,3);
    return 0;
}