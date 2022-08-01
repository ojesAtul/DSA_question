#include<bits/stdc++.h>
using namespace std;
#define int long long int 
bool cmp(int a,int b){
    return a>b;
}
void solve(){
   int n,m;
   cin>>n>>m;
   int arr[m];
   for(int i=0;i<m;i++){
    cin>>arr[i];
   }
   sort(arr,arr+m);
   vector<int>pq;
   for(int i=0;i<m;i++){
      int x=i;
      int y=(i+1)%m;
      int t=(arr[y]-arr[i]-1+n)%n;
        pq.push_back(t);
   }
    sort(pq.begin(),pq.end(),cmp);
    int cnt=0;
    int ans=0;
    for(int i=0;i<pq.size();i++){
       ans+=max(0LL,pq[i]-2*cnt-1);
    } 
    cout<<n-ans<<endl;
}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}