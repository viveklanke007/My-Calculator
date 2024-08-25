#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int sub(vector<int>&arr, int k){
    int n = arr.size();
    if(n<k){
        cerr<<"Invalid input: k is larger than array size"<<endl;
        return INT_MIN;
    }
    int max_sum = 0;
    for(int i=0;i<k;++i){
        max_sum+=arr[i];
    }
    int window_sum = max_sum;

    for(int i=k;i<n;++i){
        window_sum+=arr[i]-arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int k = 4;
    cout<<sub(arr, k);
    return 0;
}