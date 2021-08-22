#include<iostream>
#include<stack>
using namespace std;

/*
level order traversal.
change direction of traversal at each level.


Approach
1. use 2 stacks - currLevel nextLevel
2. variable left to right
3. if left to right push left child then right else push right child then left.

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

void zigzagtraversal(node* root){
    if(root == NULL){
        return;
    }
    stack<node*> currlvl;
    stack<node*> nextlvl;

    bool leftToRight = true;

    currlvl.push(root);

    while(!currlvl.empty()){
        node* temp= currlvl.top();
        currlvl.pop();
        
        if(temp){
            cout << temp->data << " ";
            

            if(leftToRight){
                if(temp->left){
                    nextlvl.push(temp->left);
                }
                if(temp->right){
                    nextlvl.push(temp->right);
                }
            }
            else{ 
                // right to left
                if(temp->right){
                    nextlvl.push(temp->right);
                }
                if(temp->left){
                    nextlvl.push(temp->left);
                }
            }
        }
        if(currlvl.empty()){
            leftToRight = !leftToRight;
            swap(currlvl , nextlvl);
        }
    }


}

int main(){

    node* root = new node (12);
    root->left = new node(9);
    root->right = new node(15);

    root->left->left = new node(5);
    root->left->right = new node(10);
    
    zigzagtraversal(root);

}