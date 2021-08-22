#include<iostream>
using namespace std;

struct node{
    int data ; 
    node* left;
    node* right;
    public:
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// creatig BST using recursive function. 
node* Insert(node* root , int val){
    if(root == NULL){
        return new node(val);
    }

    if(val < root->data){
        root->left = Insert(root->left,val);
    }
    if(val > root->data){
        root->right = Insert(root->right,val);
    }
    return root;
}

void inorser(node* root){
    if(root == NULL){
        return;
    }
    inorser(root->left);
    cout << root->data<<" ";
    inorser(root->right);
}

int main(){
    node* root = NULL;

    root = Insert(root , 5);
    Insert(root,1);
    Insert(root,2);
    Insert(root,3);
    Insert(root,4);
    Insert(root,6);
    Insert(root,7);
    Insert(root,8);
    inorser(root);
    return 0;
}