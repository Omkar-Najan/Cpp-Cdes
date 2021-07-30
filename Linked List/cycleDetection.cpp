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


void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL" << endl;
}


bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast == slow){
            return true;
        }
    }

    return false;
}

void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startnode;
    int count = 1;
    while(temp->next!= NULL){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

void removeCycle(node* &head){
    if(detectCycle(head)){
        node* fast = head;
        node* slow = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);

        fast = head;

        while(slow->next!= fast ->next){
            slow = slow->next;
            fast=fast->next;
        }
        slow->next = NULL;
        return;
    }else{
        return ;
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
    // insertAtHead(head,6);
    // display(head);
    // cout << detectCycle(head)<< " ";

    makeCycle(head,3);
    cout << detectCycle(head)<< endl;
    removeCycle(head);
    cout << detectCycle(head)<< endl;
    display(head);
    return 0;
}