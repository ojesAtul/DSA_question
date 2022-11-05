#include<bits/stdc++.h>
using namespace std;
#define mxSize 100001

int n;
map<pair<int,int>,int>directed;
vector<int>adj[100001];
int dp[mxSize];

int dfs(int node,int par){
    int ans=1;
	for(auto x:adj[node]){
		if(par==x){
			continue;
		}
		else{
          int cnt=dfs(x,node);
          if(directed.find({node,x})!=directed.end())
		     ans+=cnt+1;
		}
	}     
	return dp[node]=ans;
}
// now here this dp array will contain the count of the connect componenet 


void solve(){
	cin>>n;
	for(int i=0;i<n-1;i++){
	   int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		directed[{x,y}]=1;
	}



}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}