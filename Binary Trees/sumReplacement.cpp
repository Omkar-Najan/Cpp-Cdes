#include<iostream>
#include<queue>
using namespace std;
/*
value of node is replace by sum of its left and right child.
*/

/*
this function is getting called once for every node so Time Complexity is
O(n).
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

void sumReplacement(node* root){
    if(root == NULL){
        return ;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
        root->data += root->right->data;
    }
    return ;
}

void preorderPrint(node* root){
    
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);

}

int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    preorderPrint(root);
    sumReplacement(root);
    cout <<endl;
    preorderPrint(root);
    return 0;

}
