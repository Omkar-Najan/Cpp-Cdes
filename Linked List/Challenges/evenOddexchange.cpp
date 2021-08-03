/*
put odd position elements after odd position elements
eg. 
input : 1 2 3 4 5 6
output: 1 3 5 2 4 6
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



node* oddEvenList(node* head) {
        node* even =  head->next;
        node* odd = head;
        node* evenStart = even;
        
        while(odd->next!=NULL && even->next!=NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        if(odd->next!= NULL){
            even->next = NULL;
        }
        odd->next = evenStart;
        return head;
    }

int main(){
    node* head1 = NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);
    insert(head1,6);
    display(head1);
    oddEvenList(head1);
    display(head1);

    return 0;
}