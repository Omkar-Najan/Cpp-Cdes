#include<iostream>
using namespace std;
/*
maximun possible sum of path in binary tree, starting and ending at any node.
*/

/*

Approach:
for each node compute
1. Node val;
2. max path through left child + node val;
3. max path through right child + nodde val;
4. max path through left child + max path through right child + node val

*/

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data  = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumUtil(node* root,int &ans){
    if(root == NULL){
        return 0;
    }
    
    int lf = maxPathSumUtil(root->left , ans);
    int rt = maxPathSumUtil(root->right , ans);

    int nodemax = max(max(root->data , root->data + lf + rt) , 
                      max(root->data + lf , root->data + rt));

    ans = max(ans , nodemax);

    int singlePathSum = max(root->data , max(root->data+lf , root->data + rt));
    
    return singlePathSum;
}
int maxPath(node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

int main(){
    node* root  = new node(1);
    root->left = new node(-12);
    root->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(-6);
    

    cout << maxPath(root);
    
    return 0;

}