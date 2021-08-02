/*
Append last K nodes of link list to start of Link list
eg. LL = 
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL    K = 3;
output:
4 -> 5 -> 6 -> 1 -> 2 -> 3 -> NULL  
*/

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp-> next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

int len(node* head){
    int i=0;
    node* temp = head;
    
    while(temp!=NULL){
        i++;
        temp = temp->next;
    }
    delete temp;
    return i;
}


void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL" << endl;
}

node* appendKNodes(node* head , int k){
    cout << "2" ;
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = len(head);
    int i = 1;
    k = k%l;
    cout << "Here";
    while(tail->next != NULL){
        if( i == l-k){
         newTail = tail;
        }
        if(i == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        i+1;
    }
    newTail->next = NULL;
    tail->next = head;
    display(newHead);
    return newHead;
}







int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);

    display(head);
    int k = 3;
    cout << len(head) <<endl;
    node* newHead = appendKNodes(head,k);
    display(newHead);
    return 0;
}