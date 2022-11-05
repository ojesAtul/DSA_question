#include<bits/stdc++.h>
using namespace std;
//#define int long long int 
#define mxSize 100001


void solve(){
	int n;
	string str;
	cin>>n>>str;
	map<int,int>mp;
    int cur=0;
    int right=0;
	for(int i=0;i<n;i++){
		int idx=(str[i]-'a');
		right^=(1<<idx);
	}	
	int left=0;
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		int idx=str[i]-'a';
		//cout<<i<<' ';
        for(int j=0;j<=26;j++){
           int res;
		   if(j<26){
               res=right^(1<<j);
		   }
		   else{
             res=right;
		   }
		  // cout<<j<<' '<<res<<endl;
		   if(mp.find(res)!=mp.end()){
			  ans=min(ans,i-mp[res]-1);
		   }
		}
		right^=(1<<idx);
		left^=(1<<idx);
		mp[left]=i;
	}
	cout<<ans<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}

}