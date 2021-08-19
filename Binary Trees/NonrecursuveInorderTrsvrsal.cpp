#include<iostream>
#include<stack>
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

void inOrder(node* root){
    stack<char> st;

    while(1){
        while(root!= NULL){
            st.push(root->data);
            root = root->left;
        }

        if(st.empty()){
            break;
        }
        char ele = st.top();
        st.pop();
        cout << ele <<" ";
        root = root->right;
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
    cout << "inOrder is ";
    inOrder(root);
}