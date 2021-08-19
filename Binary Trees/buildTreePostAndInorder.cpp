#include<iostream>
using namespace std;
/*
build tree from preorder and inorder. 
*/


//
/*
Algorithm
1. start from end of postorder and pick an element to creat a node
2. decrement postorder idx
3. search for picked elements pos in inorder
4. call to build right subtree from pos+1 to n
5. call to build left subtree from inorder 0 to pos-1
6. return the node
*/
//
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

int search(int inorder[] , int start , int end , int val){
    for(int i = start ; i<=end;i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}

node* buildTree(int postorder[], int inorder[] , int start , int end ){
    static int idx = 4;
    if(start > end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    node* curr = new node(val);
    if(start == end){
        return curr;
    }

    int pos = search(inorder , start , end,val);
    curr->right = buildTree(postorder , inorder, pos+1 , end);
    curr->left = buildTree(postorder , inorder ,start, pos-1);
    return curr;
}

void PrintTree(node* root){
    if(root == NULL){
        return;
    }
    PrintTree(root->left);
    cout << root->data <<" ";
    PrintTree(root->right);
    
}


int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1 , 5 ,3};

    node* root = buildTree(postorder , inorder , 0,4);
    PrintTree(root);
    return 0;
}

