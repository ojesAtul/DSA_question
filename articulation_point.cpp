// removing a node increase the number of connected componenet int the graph
#include<bits/stdc++.h>
using namespace std;
#define mxSize 100001
int low[mxSize];
int in[mxSize];
vector<int>adj[mxSize];
int timer={0};
int ans[mxSize];
int vis[mxSize];

void dfs(int node,int par){
   vis[node]=1;
   in[node]=low[node]=timer++;
   int child=0;
   for(auto x:adj[node]){
	  if(vis[node]==0){
		 dfs(x,node);
		 child++;
		 if(par!=-1 && low[x]==in[node])
		   ans[node]=true;
		 low[node]=min(low[node],low[x]);  
	  }
    else{
		low[node]=min(low[node],in[x]);
	}   
   }
   if(par==-1 && child>1)
      ans[node]=true;   

}


