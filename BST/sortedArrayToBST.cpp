#include<iostream>
using namespace std;
/*
build a balanced tree from sorted array.
1. make middle element as root
2. recursively do same for subtree. 
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

node* sortedToBST(int arr[] , int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    node* root = new node(arr[mid]);

    root->left = sortedToBST(arr,start,mid-1);
    root->right = sortedToBST(arr,mid+1,end);

    return root;
}


int main(){

    int arr[] = {10,20,30,40,50,60,70};
    node* root = sortedToBST(arr,0,6);

    preorderPrint(root);
    return 0;
}