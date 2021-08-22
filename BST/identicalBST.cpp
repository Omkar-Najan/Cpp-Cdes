#include<iostream>
using namespace std;
/*
for a gien 2 bst print if bst are identical or not. 
identical bst are structurally identical and have equal
values for the nodes in the structure
*/

/*
Approach:
    1. if both empty return true.
    2. if both nodes are non empty
        a. if data at nodes are equal
        b. check if left subtree are equal.
        c. check if right subtree are equal.
    3. if all conditions are true then return true.

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

bool isequal(node* root1 , node* root2){
    
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }else{
        bool cond1 = root1->data == root2->data;
        bool cond2 = isequal(root1->left , root2->left);
        bool cond3 = isequal(root1->right , root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }
    

}


int main(){

    node* root1 = new node(1);
    root1->left = new node(3);
    root1->right = new node(5);

    node* root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(5);

    cout << isequal(root1,root2);
    return 0;
}