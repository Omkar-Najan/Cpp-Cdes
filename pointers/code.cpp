#include<iostream>
using namespace std;
void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}
void swapptr(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    // int a = 10;
    // int* aptr;
    // aptr = &a;
    // cout << *aptr<< endl;
    // *aptr = 20;
    // cout << a<<endl;
    // cout << aptr <<endl;

    // arrays pointers
    // int arr[] = {10,20,30};
    // cout << *arr << endl;
    // int* ptr = arr;
    // for(int i = 0; i<3;i++){
    //     cout << *ptr << endl;
    //     ptr++;
    // }
    // for(int i = 0; i<3;i++){
    //     // cout << *arr << endl;
    //     // arr++; is illegal.
    //     cout << *(arr+i) << endl;
    // } 

    // Pointers to Pointers
    // int a = 10;
    // int *p;
    // p = &a;
    // cout << *p<< endl; // 10 value at memory location reffrenced at p
    // int **q = &p;
    // cout << *q<<endl; // value stores at memory location reffrenced at q  i.e. adress of p
    // cout << **q<<endl; // 10. reff q -> reff p -> a.

    // Passing pointers to functions.
    // pass values py reffrences
    // int a = 2,b = 4;
    // swap(a,b);
    // cout << a<<b << endl;

    // int *aptr = &a;
    // int *bptr = &b;
    // swapptr(aptr,bptr);
    // cout << a<<b << endl;
    return 0;
}
