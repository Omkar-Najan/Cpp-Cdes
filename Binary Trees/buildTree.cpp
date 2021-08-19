#include<iostream>
using namespace std;




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

int search(int inOrder[] , int start , int end , int curr){
    for(int i = start ; i<=end;i++){
        if(inOrder[i] == curr){
            return i;
        }
    }
    return -1;
}

node* buildTree(int preOrder[], int inOrder[], int start , int end){
    static int idx = 0;
    if(start > end){
        return NULL;
    }
    int curr = preOrder[idx];
    idx++;
    node* temp =  new node(curr);
    if(start == end){
        return temp;
    }
    int pos = search(inOrder , start , end , curr);
    temp->left = buildTree(preOrder,inOrder,start, pos-1);
    temp->right = buildTree(preOrder , inOrder,pos+1,end);

    return temp;
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
    int preOrder[] = {1, 2, 4, 7, 8 ,5 ,9 ,3 ,6 ,10 };
    int inOrder[] =  {7,4, 8, 2, 5, 9, 1, 6, 10, 3};

    // cout << inOrder[0];
    // build Tree
    node* root = buildTree(preOrder , inOrder,0,9);

    inorderPrint(root);
    return 0;
}