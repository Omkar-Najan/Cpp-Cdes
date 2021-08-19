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


void printLevelOrder(node* root){
    if(root == NULL){
        return;
    }
    int lvl = 0;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    lvl++;
    cout<< "level is " << lvl << endl;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp != NULL){
            cout << temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            cout << endl;
            q.push(NULL);
            lvl++;
            cout<< "level is " << lvl << endl;;
        }
    }
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
    printLevelOrder(root);
}