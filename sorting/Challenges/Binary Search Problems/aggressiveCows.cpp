#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool canplace(vector<int>&arr, int n, int c, int dist){
    int cow_one = arr[0]; int cnt  =1;
    for(int i= 1 ;i<n;i++){
        if(arr[i] - cow_one >= dist){
            cow_one = arr[i];
            cnt++;
        }
        if(cnt == c) return true;   
    }
    return false;
}


int main(){
    int t, n, c;
    vector<int> arr;
    while(t--){
        cin >> n >> c;
        while(n--){
            int i;
            cin >>i; 
            arr.push_back(i);
        }

        sort(arr.begin(), arr.end());
        int low = 1;
        int high = arr[n-1]-arr[0];
        int res = 0;
        while(low<=high){
            int mid = (low+high)>>1;

            if(canplace(arr, n,c,mid)){
                res = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }        
        cout << res << endl;
    }
    return 0;
}