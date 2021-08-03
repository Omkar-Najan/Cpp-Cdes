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

node* merge(node* h1, node* h2){
    node* dummynode = new node(-1) ;
    node* p1 = h1;
    node* p2 = h2;
    node* p3 = dummynode;

    while(p1 !=NULL && p2 !=NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;

        }else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1!=NULL){
        p3->next = p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummynode->next;
}


node* recursiveMerge(node* h1,node* h2){
    
    if(h1 == NULL){
        return h2;
    }
    if(h2 == NULL){
        return h1;
    }
    
    node* result;
    if(h1->data < h2->data){
        result = h1;
        result->next = recursiveMerge(h1->next,h2);
    }
    else{
        result = h2;
        result->next = recursiveMerge(h1,h2->next);
    }
    return result;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);
    insert(head1,6);
    insert(head2,7);
    insert(head2,8);
    insert(head2,9);
    insert(head2,10);
    insert(head2,11);
    insert(head2,12);

    display(head1);
    display(head2);

    node* sorted = recursiveMerge(head1,head2);
    display(sorted);

    return 0;
}