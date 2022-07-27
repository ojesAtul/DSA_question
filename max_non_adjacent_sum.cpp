
#include<bits/stdc++.h>
using namespace std;
int max_non_adj_sum(vector<int>arr){
    int n=arr.size();
    int dp[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
       dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
    }
    return dp[n-1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        max_non_adj_sum({1,3});
    }
}