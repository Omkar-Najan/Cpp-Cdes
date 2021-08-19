#include<iostream>
#include<queue>
using namespace std;

/*
left most nodes. nodes can be seen from left of tree
                1
              /   \
            2       3
          /       /  \
        4       5      6
              /  
            7

left view will be 1,2,4,7
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


void leftView(node* root){

    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            node* curr = q.front();
            q.pop();

            if(i == 0){
                cout << curr->data << " ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->right->left = new node(5);

    root->right->right = new node(6);
    root->right->left->left = new node(7);

    leftView(root);

}