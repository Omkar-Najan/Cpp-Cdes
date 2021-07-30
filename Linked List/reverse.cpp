/*
reverse k nodes in Link list.
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


void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<"->";
        temp = temp -> next;
    }
    cout<<"NULL" << endl;
}


void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}


bool search(node* head ,int key){
    node* temp = head;
    while(temp!= NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int len(node* head){
    int i=0;
    node* temp = head;
    
    while(temp!=NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

void insertAtK(node* &head,int val,int pos){
    int k = len(head);
    if(pos > k+1){
        // cout << "can not insert node";
        return;
    }
    else{
        node* n = new node(val);
        node* temp = head;
        int i=0;
        // cout << "Node is inserting"<<endl;
        while(temp->next !=NULL && i<pos-1){
            i++;
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        return;
    }
}

void delval(node* &head,int val){
    node* temp = head;
    if(head == NULL){
        return;
    }
    if(head->data == val || head->next ==NULL){
        head = head->next;
        return;
    }
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next =temp->next->next;
    delete todelete;
}

node*  reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next; 

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

node* reverseRecursive(node* &head){
    
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}


int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insertAtHead(head,6);
    display(head);
    cout << search(head,3)<<endl;
    cout << "lenght of Link List is " << len(head)<<endl;
    // insert value at pos 'k'.
    insertAtK(head,8,3);
    display(head);
    delval(head,6);
    display(head);
    // cout << head->data;
    node* newhead = reverse(head);
    node* newheadrecur = reverseRecursive(head);
    display(newhead);
    display(newheadrecur);
    return 0;
}