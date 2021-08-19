#include<iostream>
using namespace std;

struct node{
    char data;
    struct node* left;
    struct node* right;

    node(int val){
        data  = val;
        left = NULL;
        right = NULL;
    }
};
// Preorder traversal recursive

void preOrder(node* temp){
    if(temp!=NULL){
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
// PostOrder ecursive
void postOrder(node* temp){
    if(temp!=NULL){
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
}

// inorder Resursive
void inOrder(node* temp){
    if(temp!=NULL){
        inOrder(temp->left);
        cout << temp->data <<" ";
        inOrder(temp->right);
    }
}

int main(){
    struct node* root = new node('a');
    root->left = new node('b');
    root->right = new node('c');
    root->left->left = new node('d');
    root->left->right = new node('e');
    root->left->left->left = new node('g');
    root->left->left->right = new node('h');
    root->left->right->right = new node('i');
    root->right->left = new node('f');
    root->right->left->right = new node('j');
    cout << "PreOrder is ";
    preOrder(root);
    cout << endl;
    cout << "PostOrder is ";
    postOrder(root);
    cout << endl;
    cout << "inOrder is ";
    inOrder(root);

}