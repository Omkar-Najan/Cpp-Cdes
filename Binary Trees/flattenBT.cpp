#include<iostream>
#include<queue>
using namespace std;

/*
Flatten a BT.
Given a BT flatten into a linkedlist in place. After flattening left of each node should point to
 NULL and right should contain next node in preorder sequence.
(not allowed to use other data structure)
*/

/*
        1                 1
      /   \                \
    2       3       ->      2    
          /                  \  
        4                     3
                               \
                                4

*/

/*
Approach
1. recursively flatten left and right subtree.
2. store left tail and right tail.
3. store right subtree in temp and make left subtree as right subtree.
4. join right subtree with left tail.
5. return right tail. 

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


void flatten(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        node* t = root->right; // to calculate root->right tail.
        while(t->right !=NULL){
            t = t->right;
        }

        t->right = temp;
    }
    
    flatten(root->right);
}


void inorderPrint(node* root){
    
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout << root->data <<" ";
    inorderPrint(root->right);

}

int main(){
    node* root  = new node(4);
    root->left = new node(9);
    root->right = new node(5);

    root->left->left = new node(1);
    root->left->right = new node(3);

    root->right->right = new node(6);

    inorderPrint(root);
    cout << endl;
    flatten(root);
    inorderPrint(root);

}