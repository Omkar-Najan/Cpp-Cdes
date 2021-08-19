#include<iostream>
#include<queue>
using namespace std;
/*
Diameter of a Tree is a number of nodes in longest path between any 2 nodes.
1. root can be included in diameter.
2. root can not be included in diameter.
*/
/*
Timecomplexity:

timecomplexity of height function is O(n).
this function is called for every node.

so O(n^2)
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
int calcHeight(node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight,rHeight)+1;
}

int calcdiameter(node* root){ // O(n^2)
    if(root == NULL){
        return 0;
    }
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    int currDiameter = lheight + rheight + 1;

    int lDiameter = calcdiameter(root->left);
    int rDiameter = calcdiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}


int diameter(node* root , int* height){ // O(n) as height is calculated ans stored in pointer.
    if(root ==NULL){
        *height = 0;
        return 0;
    }
    int lh = 0,rh = 0;
    int lDiameter = diameter(root->left,&lh);
    int rDiameter = diameter(root->right,&rh);

    int currDia = lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currDia , max(lDiameter,rDiameter));
}


int main(){
    node* root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    int height = 0;
    cout << "diameter is "<< diameter(root,&height);
}
