#include<iostream>
using namespace std;
/*
case 1: leaf node
    delete node directly.

case 2: node has 1 child.
    replace node with child.

case 3: node has 2 child
    find inoder successor - value that comes after node in inorder representation.
    replace that node with inorder successor and delete node.

*/
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
// delete node

node* inorderSucc(node* root){
    node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}


node* deleteBST(node* root , int key){

    if(key < root->data){
       root->left =  deleteBST(root->left,key);
    }else
    if(key>root->data){
        root->right = deleteBST(root->right , key);
    }
    else{
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right , temp->data);
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    root = Insert(root , 4);
    Insert(root , 2);
    Insert(root , 5);
    Insert(root , 1);
    Insert(root , 3);
    Insert(root , 6);

    inorder(root);
    cout << endl;
    root = deleteBST(root , 5);
    inorder(root);
    
    return 0;
}