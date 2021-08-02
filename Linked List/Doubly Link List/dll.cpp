#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insert(node* &head, int val){
    node* temp = head;
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }
    while(temp != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = NULL;
    return;
}

void insertAtHead(node* &head , int val){
    node* temp = head;
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
    return;


}


void display(node* head){
    node* temp = head;
    if(head == NULL){
        cout << "EMPTY LIST" << endl;
        return;
    }
    while(temp !=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL" << endl;
    return ;
}

void deletion(node* &head,int val){
    node* temp = head;
    if(head->data = val){
        head = head->next;
        head->prev = NULL;
        delete(temp);
        return;
    }
    while(temp->data !=val && temp != NULL){
        temp = temp->next;
    }
    
    temp->prev->next = temp->next;

    if(temp->next!=NULL){
    temp->next->prev = temp->prev;
    }

    delete temp;
    return;
}



int main(){
    node* head = NULL;
    display(head);
    insert(head,6);
    insertAtHead(head,9);
    display(head);
    // cout << head->data;
    deletion(head,9);
    display(head);
    deletion(head,6);

    return 0;
}