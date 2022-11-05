#include<bits/stdc++.h>
using namespace std;
//#define int long long int
#define mxSize 100001
#define lli long long int
int tree[4*mxSize];
int arr[mxSize];
int n;
void buildtree(int si,int ss,int se){
	if(ss==se){
		tree[si]=arr[ss];
		return;
	}
	int mid=(ss+se)/2;
	buildtree(2*si,ss,mid);
	buildtree(2*si+1,mid+1,se);
	tree[si]=tree[2*si]+tree[2*si+1];
}
int  query(int si,int ss,int se,int k){
	if(ss==se){
		return ss;
	}
  int mid=(ss+se)/2;
  if(tree[si*2+1]>=k){
	return query(2*si+1,mid+1,se,k);
  }
  else{
	return query(2*si,ss,mid,k-tree[2*si+1]);
  }
}

void update(int si,int ss,int se, int idx){
	 if(ss==se){
		arr[ss]=0;
		tree[si]=0;
		return;
	 }
	 int mid=(ss+se)/2;
	 if(mid<idx){
		update(2*si+1,mid+1,se,idx);
	 }
	 else{
		update(2*si,ss,mid,idx);
	 }
	 tree[si]=tree[2*si]+tree[2*si+1];
}



void solve(){
   int n;cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
     cin>>a[i];
   for(int i=1;i<=n;i++){
	 arr[i]=1;
   }

   buildtree(1,1,n);
   vector<int>ans;
   for(int i=n-1;i>=0;i--){
	   int t=query(1,1,n,a[i]+1);
	   ans.push_back(t);
	   update(1,1,n,t);
   }
   for(int i=n-1;i>=0;i--)
     cout<<ans[i]<<' ';
	 cout<<endl;
   

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    lli t=1;
    //cin>>t;
    for(lli i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}