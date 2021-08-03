/*
Find intersection of 2 linked list
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

int interection(node* &head1 , node* &head2){
    int l1 = len(head1), l2 = len(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1 > l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;

    }else{
        d = l2 - l1;
        ptr2 = head1;
        ptr1 = head2;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
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

    return 0;
}