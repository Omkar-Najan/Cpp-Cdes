#include<iostream>
#include<queue>
using namespace std;

/*

find all nodes present at given distance k from given node n.
Given: Root, target node n, distance k.

case1: distance from child
case2: distance from ansesters.
    if ansester is at distance d
    find all other subtrees at distance k-d.

    if target is in left subtree of ansester the find in right subtree and vice versa.

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


// case 1
void printSubtreenodes(node* root , int k ){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0 ){
        cout << root->data << " ";
        return;
    }
    printSubtreenodes(root->left,k-1);
    printSubtreenodes(root->right,k-1);
}

// case 2

int  printodesatK(node* root ,node*target,int k){
    
    if(root == NULL){
        return -1;
    }

    if(root == target){
        printSubtreenodes(root , k);
        return 0;
    }

    int dl = printodesatK(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout << root->data;
        }
        else{
            printSubtreenodes(root->right , k-dl-2);
        }
        return 1+dl;
    }
    int dr = printodesatK(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout << root->data;
        }
        else{
            printSubtreenodes(root->left , k-dr-2);
        }
        return 1+dr;
    }

    return -1;

}


int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);

    printodesatK(root , root->left , 2);
    return 0;



}