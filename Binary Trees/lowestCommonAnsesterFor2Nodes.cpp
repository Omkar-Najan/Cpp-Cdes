#include<iostream>
#include<vector>
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

bool getPath(node* root , int key,vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    if(getPath(root->left ,key,path) || getPath(root->right ,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}

/*
Time Complexity : We are calling function on node multiple time.
*/

int LCA(node* root , int n1,int n2){
    vector<int> path1, path2;

    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }

    int pc;
    for(pc = 0;pc<(path1.size() && path2.size());pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc];

}

node* LCAOptimized(node* root, int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftLCA = LCAOptimized(root->left , n1,n2);
    node* rightLCA = LCAOptimized(root->right , n1,n2);

    if(leftLCA && rightLCA){
        return root;
    }
    if(leftLCA != NULL){
        return leftLCA;
    }

    return rightLCA;

}

int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);

    root->right->left->left = new node(7);
    
    int n1 = 7;
    int n2 = 6;

    int lca = LCA(root , n1,n2);

    if(lca==-1){
        cout << "LCA Doesn't exist";
    }
    else{
        cout <<"LCA is " << lca << endl;
    }

    // node* lca2 = LCAOptimized(root , n1,n2);

    // if(lca2){
    //     cout <<"LCA is " << lca2->data << endl;
    // }
    // else{
    //     cout << "LCA Doesn't exist";
    // }
    return 0;

}