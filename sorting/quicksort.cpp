#include<iostream>
using namespace std;

void swap(int arr[], int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i= l-1;
    for(int j = l;l<r;l++){
        if(arr[j] <=  pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void Quicksort(int arr[],int l,int r){
    if(l<r){
        int pivot = partition(arr,l,r);
        Quicksort(arr,l,pivot-1);
        Quicksort(arr,pivot+1,r);
    }

}

int main(){
    int arr[5] = {5,6,5,6,1};
    Quicksort(arr,0,4);
    for(int i = 0;i<5;i++){
        cout << arr[i]<<" ";
    }
    return  0;
}