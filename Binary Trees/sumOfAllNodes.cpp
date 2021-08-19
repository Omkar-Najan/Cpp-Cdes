#include<iostream>
#include<queue>
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


int sumOfAllNodes(node* root){
    if(root==NULL){
        return 0;
    }
    queue<node*> q;
    int result = 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp!=NULL){
            result = result + temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    return result;
}

// Approach 2
int sumResursive(node* root){
    if(root == NULL){
        return 0;
    }
    return sumResursive(root->left)+ sumResursive(root->right)+root->data;
}

int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);


    // Level Order
    cout << "sum is "<< sumOfAllNodes(root);
    cout << "sum is "<< sumResursive(root);
}