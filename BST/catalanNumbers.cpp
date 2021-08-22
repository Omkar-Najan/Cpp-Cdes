#include<iostream>
using namespace std;
/*
catalan numbers :
    sequence of natural numbers that occur in various counting problems, often involving 
    recursively defined objects.
closed form in terms of binomial coefficients:
    C(n) =  sum of c(i) * c(n-1)
    
    c(0) = 1
    C(1) = 1
    C(2) = 2
    C(3) = 5 

Application:
1.  Count the number of expressions containing n pairs of parentheses which are correctly matched. 
    For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
2.  Count the number of possible Binary Search Trees with n keys (See this)
3.  Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) 
    with n+1 leaves.
4.  Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.


Applications of Catalan numbers
1. Possible BST.
2. Parathensis/ basket combinations
3. Possible forest
4. possible ways to find path in matrix
5. Dividing circles in N chords.
6. Dyck words of given length etc.

*/
struct node{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};


// recurive solution exponential complexity. 
unsigned long int catalan(unsigned int n){
    if(n<= 1){
        return 1;
    }
    unsigned long int res = 0;
    for(int i = 0;i<n;i++){
        res += catalan(i)  * catalan(n-i-1);
    }
    return res;
}

// Dynamic Programming solution
// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n){
    
    // Table to store results of subproblems
    unsigned long int cat[n + 1];
    
    // Initialize first two values in table
    cat[0] = cat[1] = 1;
    
    // Fill entries in catalan[] using recursive formula
    for(int i =2;i<=n;i++){
        cat[i] = 0;
        for(int j = 0;j<i;j++){
            cat[i] += cat[j]*cat[i-j-1];
        }
    }
    return cat[n];
} // time complexity O(n^2);


// Using Binomial Coefficient Time complexity O(n)
// Returns value of Binomial Coefficient C(n, k)
unsigned long int BinomialCoeff(unsigned int n, unsigned int k){
    unsigned int res = 1;

    // since C(n,k) = c(n,n-k);
    if(k>n-k){
        k = n-k;
    }

    // Calculate value of [n*(n-1)*---*(n-k+1)]
    // [k*(k-1)*---*1]
    for(int i = 0;i<k;i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

unsigned long int catalanBC(unsigned int n){
    unsigned long int c = BinomialCoeff(2*n , n);
    return c/(n+1);
}



int main(){
    for(int i = 0;i<=10;i++){
        cout << catalan(i) << " "; // recursive implementation.
    }
    cout << endl;
    for(int i = 0;i<=10;i++){
        cout << catalanDP(i) << " "; // Dynamic Programming  implementation.
    }
    cout << endl;
    for(int i = 0;i<=10;i++){
        cout << catalanBC(i) << " "; // Binomial coefficient implementation.
    }

    return 0;
}