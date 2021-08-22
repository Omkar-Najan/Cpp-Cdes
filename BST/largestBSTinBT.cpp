/*
find the largest binary search tree in given binary tree.
return the size of largest binary tree from given BT.
*/

/*
Approach : for each node store the following info.
1. min in subtree
2. max in subtree
3. subree size
4. size of largest BST.
5. isBST.
*/

/*
recursively traverse in bottom up manner and 
find out size of largest bst.
*/

#include<iostream>
#include<climits>
using namespace std;

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

struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBSTinBT(node* root){
    // base cases
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    // call to left and right subtree
    info leftinfo = largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);

    // for current level
    info curr ;

    curr.size = (1 + leftinfo.size + rightinfo.size);

    // if left subtree is bst , right tree is bst and curr node also satisfies condition of bst.
    if(leftinfo.isBST && rightinfo.isBST && leftinfo.max < root->data && root->data < rightinfo.min ) {
        curr.min = min(leftinfo.min , min(root->data , rightinfo.min));
        curr.max = max(leftinfo.max , max(root->data , rightinfo.max));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    // any one of above condition does satisfied.
    curr.ans = max(leftinfo.ans , rightinfo.ans);
    curr.isBST = false;

    return curr;

}



int main(){
    node* root       = new node(15);
    
    root->left       =  new node(20);
    root->right      =  new node(30);

    root->left->left =  new node(5);
    cout << "Largest BST in BT : " << largestBSTinBT(root).ans << endl;

    return 0;
}