#include<iostream>
using namespace std;
/*
Count the inversions in the given array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

A: [3, 5, 6, 9, 1, 2, 7, 8]
Inversions: 10
Explanation: (3,1), (3,2), (5,1), (5,2), (6,1), (6,2), (9,1), (9,2), (9,7), (9,8
*/
// Brut force see 19.3

long long merge(int arr[],int l,int mid,int  r){
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r- mid;
    int a[n1],b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }

    for(int i=0;i<n2;i++){
        b[i] = arr[mid+i+1];
    }

    int i = 0,j=0,k=l;
    while(i<n1 and j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++;i++;
        }else{
            arr[k] = b[j];
            k++;j++;
            inv += n1-i;    // because if firt element is having inversion, 
                            //all other elements also having inversion.
        }
    }
    while(i<n1){
        arr[k] = a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;k++;
    }

    return inv;
}



long long mergesort(int arr[],int l,int r){
    long long inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += mergesort(arr,l,mid);
        inv += mergesort(arr,mid+1,r);

        inv += merge(arr,l,mid,r);
    }
    return inv;
}


int main(){
    int arr[] = {2,3,9,2,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << mergesort(arr,0,n-1);
    return 0;
}