#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

/*
1. start ith root node.
2. recursively call left and right with hd-1 and hd+1 as arguments.
vase case node = null return. 
3. push values into vector corrosponding to horizontal distance.(HD).
*/
/*
Time complexity : O(NlogN)
*/

struct node{
    int key;
    node* left, *right;
    
    node(int val){
        key = val;
        left = NULL;
        right = NULL;
    }
};

void getVerticalOrder(node*root, int hd,map<int,vector<int>> &m){
    if(root == NULL){
        return ;
    }

    m[hd].push_back(root->key);
    getVerticalOrder(root->left , hd-1 , m);
    getVerticalOrder(root->right , hd+1 , m);

}

int main(){
    node* root = new node(10);
    root->left = new node(7);
    root->right = new node(4);

    root->left->left = new node(3);
    root->left->right = new node(11);
    
    root->right->left  = new node(14);
    root->right->right = new node(6);

    map<int,vector<int>> m;

    int hd = 0;

    getVerticalOrder(root,hd,m);
    map<int , vector<int>> :: iterator it;

    for(it = m.begin() ; it!=m.end();it++){
        for(int i = 0;i<it->second.size() ; i++){
            cout << (it->second)[i]<<" ";
        }
        cout << endl;
    }
}