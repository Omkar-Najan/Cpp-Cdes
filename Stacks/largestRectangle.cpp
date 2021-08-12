/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have same width and the width is 1 unit. 
For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 1, 6}. 
The largest possible rectangle possible is 12 (see the below figure, the max area rectangle is highlighted in red)
*/

/*
Divide ans conquer 
Time Complexity: O(nLogn)
1. find min value in array.
2. One we have max value then area is max of following 3 values.
    a. Maximum area in left side of minimum value(Not including Min)
    b. Maximum area in right side of minimum value(Not including min value)
    c. Numbers of bars multiplied by min value.

3. Area on left or right can be calculated recursively.
4. To find min efficientlly use range minimum query using segment tree.
5. It takes (Log n time).
Attemt after learning segment tree.
*/

/*
using stack
1. create an empty stack
2. start with first bar and do following for every bar hist[i]
    a. if stack is empty or hist[i] > st.top() then push i to stack.
    b. if hist[i] < st.top() then keep removing the top of stack while top of stack while top of stack is greater.
        let the removed bar be hist[tp]. calculate area of rectangle with hist[tp] as smaller bar.For hist[tp], 
        the 'left index' id previous item in stack and right index is 'i'.
3. if stack is not empty, then pop all items one by one and so step 2.b 

*/

#include<iostream>
#include<stack>
using namespace std;

int getMaxArea(int hist[] , int n){
    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights
    stack<int> st;
    int max_area = 0; // Initialize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while(i<n){
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if(st.empty() || hist[st.top()] <= hist[i]){
            st.push(i++);
        }else{
            tp = st.top();
            st.pop();
            area_with_top = hist[tp] * (st.empty() ? i:i-st.top()-1);
            if(max_area < area_with_top){
                max_area = area_with_top;
            }
        }
    }
    while( ! st.empty()){
        tp = st.top();
            st.pop();
            area_with_top = hist[tp] * (st.empty() ? i:i-st.top()-1);
            if(max_area < area_with_top){
                max_area = area_with_top;
            }
    }

    return max_area;
}

int main()
{
    int hist[] = {2,1,5,6,2,3};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}