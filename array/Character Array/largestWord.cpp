#include<iostream>
using namespace std;
// Check Palindrome
int main(){
    int n;
    cin >> n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currlen = 0, maxlen =0;
    int st= 0, maxSt = 0;
    while(i<n){
        if(arr[i] == ' ' || arr[i] == '\0'){
            if(currlen > maxlen){
                maxSt = st;
                maxlen = currlen;
            }
            st = i + 1;
            currlen = 0;
        }
        else{
        currlen++;
        }
        
        if(arr[1] =='\0'){
            break;
        }
        i++;
    }
    cout << arr << endl;
    cout << maxlen <<endl;
    for(int i =0;i<maxlen;i++){
        cout << arr[maxSt + i];
    }
    return 0;
}