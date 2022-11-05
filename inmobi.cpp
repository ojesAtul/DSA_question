#include<bits/stdc++.h>
using namespace std;
#define int long long int 


///////// question1 
/*
pair<int,int> dfs(int node,vector<int> adj[]){
	//cout<<"this is root"<<' '<<node<<endl;
    if(adj[node].empty()){
		return {0,1};
	}
	int ans=0;
	int sz=1;
	for(auto x:adj[node]){
		pair<int,int>p=dfs(x,adj);
		ans+=p.first;
		sz+=p.second;
	}
	if(sz%2==0){
		return {ans+1,0};
	}
	else{
		return {ans,sz};
	}
	
}
void solve(){
	int n,two;
	cin>>n>>two;
	vector<int>adj[n+1];
	vector<int>in(n+1,0);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		in[b]++;
	}
	int root=-1;
	for(int i=1;i<=n;i++){
		if(in[i]==0)
		 {
			root=i;
			break;
		 }
	}
	cout<<dfs(root,adj).first-1<<endl;
}
///////////////// second 
void solve(){
	int n;
	cin>>n;
	multiset<int>s;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
        s.insert(x);
	}
	while(!s.empty()){
		int sz=s.size();
		if(s.find(sz)!=s.end()){
			s.erase(sz);
		}
		else{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}

*/////////////////third

bool strcm(string &str,int pos,int len){
	 int i=pos-len;
	 int j=pos;
	 for(;i<pos;i++){
		if(str[i]<str[j])
		  return true;
		else if(str[i]>str[j])
		  return false;    
		j++;
	 }
	 return false;
}
map<pair<int,int>,int>mp;
int mod=1e9+7;
int  fun(string &year,int pos,int last){
	if(pos==year.size()){
		return 1;
	}
	else if(pos>year.size())
	return 0;
	else if(year[pos]=='0')
	  return 0;
    int ans=0;
	if(strcm(year,pos,last))
	  ans=(ans+fun(year,pos+last,last));
    for(int i=last+1;i<=year.size()-pos;i++)
	{
		ans=(ans+fun(year,pos+i,i))%mod;
	}
	return mp[{pos,last}]=ans%mod;
}
void solve(){
	int n;
	string str;
	cin>>str;
	map<pair<int,int>,int>mp;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+fun(str,pos,pos));
	}
 cout<<ans<<endl;

}
int fun(int N,string S){
    int l=0,
}


int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}