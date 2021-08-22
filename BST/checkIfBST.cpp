#include<iostream>
using namespace std;
/*
Approach 1:
max of left ssubtree(maxL)
max of right subtree(maxR)

maxL < node < maxR

multiple traversal of trees.

Approach 2:
min allowed
max allowed

min allowed < node < max allowed
single traversal of node.

for left (min,  node)
for right (node,  max)
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
void preorderPrint(node* root ){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}


// Check for BST
bool isBST(node* root , node* min = NULL , node* max=NULL){
    if(root == NULL){
        return true;
    }
    if(min!= NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }

    bool leftvalid = isBST(root->left , min,root);
    bool rightvalid = isBST(root->right , root,max);

    return leftvalid && rightvalid;
}


int main(){

   node* root =  new node(2);
   root->left = new node(1);
   root->right = new node(3);
   
   cout << isBST(root,NULL,NULL) << endl;
}