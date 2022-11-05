#include<bits/stdc++.h>
using namespace std;
#define int long long int 

#define sz 22 
map<int,int>mp[sz][sz];
int arr[sz][sz];
int n,m,k,mid;
int ans;
void dfs1(int x,int y,int XOR){
	
	if(x+y-2==mid){
		mp[x][y][XOR^arr[x][y]]++;
		return;
	}
	if(x+1<=n)
	dfs1(x+1,y,XOR^arr[x][y]);
	if(y+1<=m)
	dfs1(x,y+1,XOR^arr[x][y]);
}
void dfs2(int x,int y,int XOR){
    if(n-x+m-y == n+m-2-mid){
		ans+=mp[x][y][k^XOR];
		return;
	}
	if(x>1)
	dfs2(x-1,y,XOR^arr[x][y]);
	if(y>1)
	dfs2(x,y-1,XOR^arr[x][y]);
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		  cin>>arr[i][j];
	}
	 mid=(n+m-2)/2;
	ans=0;
	dfs1(1,1,0);
	dfs2(n,m,0);
	cout<<ans<<endl;
}
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    solve();
}