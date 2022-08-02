#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool cmp(int a,int b){
    return a%10<=b%10;
}
void solve(){
 int n;
 cin>>n;
 int arr[n];
 unordered_map<int,vector<int> >mp;

 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }
 sort(arr,arr+n);
 for(int i=0;i<n;i++)
 {
   if(arr[i]%10==0){
    mp[0].push_back(arr[i]);
   }
   else if(arr[i]%10==5)
    mp[5].push_back(arr[i]);
    else{
        mp[3].push_back(arr[i]);
    } 
 }
if(mp.size()>2){
    cout<<"NO"<<endl;
}
else if(mp.size()==2){
  if(mp.find(3)!=mp.end()){
    cout<<"NO"<<endl;
  }
  else{
    if(mp[0].size()>2&&mp[0][0]!=mp[0].back()){
        cout<<"NO"<<endl;
    }
    else if(mp[5].size()>2&&mp[5][0]!=mp[5].back()&&mp[5][0]+5==mp[0][0]){
        cout<<"NO"<<endl;
    }
  }
}
else if(mp.size()==1&&mp.find(0)==mp.end()&&mp.find(5)==mp.end()){
    cout<<"YES"<<endl;
}
else{
    if(mp[0].size()>1&&mp[0][0]!=mp[0].back()){
       cout<<"NO"<<endl;
    }
    else if()
}



}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}