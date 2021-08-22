#include<iostream>
#include<climits>
using namespace std;
/*
2 nodes of BST are swapped. Task is to restore BST.
*/
/*
Approach
Inorder BST is sorted. so 2 swapped elements in swapped array.

Case 1: 
    swapped elements are not adjacent to each other.

Case 2:
    swapped elements are adj to each other.

* maintain 3 pointers- first last mid. 

case 1: {1,8,3,4,5,6,7,2}
    first = previous node where 1st num < previous; [8]
    mid = number where 1st number < previous ;[3]
    last = 2nd node where number < previous;[2]

    swap first and last. 
    {1,2,3,4,5,6,7,8}

case 2: {1,2,4,3,5,6,7,8}
    first = previous node where number < previous;[4]
    mid = munber where 1st number < previous;[3]
    last = NULL;
    {1,2,3,4,5,6,7,8}

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

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void calcPointers(node* root , node** first, node** mid ,node** last , node** pre){
    if(root == NULL){
        return;
    }

    calcPointers(root->left , first,mid,last,pre);
    if(*pre && root->data < (*pre)->data){
        if(!*first){
            *first = *pre;
            *mid = root;
        }else{
            *last = root;
        }
    }

    *pre = root;

    calcPointers(root->right , first,mid,last,pre);
}


void restoreBST(node* root){
    node* first , *pre;
    node* mid ,*last;
    first = NULL;
    mid   = NULL;
    last  = NULL;
    pre   = NULL;

    calcPointers(root , &first,&mid,&last,&pre);
    // case 1:

    if(first && last){
        swap(&(first->data), &(last->data));
    }else     // case 2:
    if(first && mid){
        swap(&(first->data) , &(mid->data));
    }



}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

int main(){
    node* root = new node(6);
    
    root->left = new node (9);
    root->right = new node(3);

    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);
    return 0;
}