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

node* search(node* root , int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return search(root->left , key);
    }

    return search(root->right , key);
}


int main(){
    node* root = NULL;
    root = Insert(root , 4);
    Insert(root , 2);
    Insert(root , 5);
    Insert(root , 1);
    Insert(root , 3);
    Insert(root , 6);

    node* temp = search(root , 9);
    if(temp){
        cout<<"Key exists " << temp->data <<endl;
    }else{
        cout <<"Key doesn't exist";
    }
    return 0;
}