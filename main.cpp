#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve(int Case){ 
  int n,x,y;
  cin>>n>>x>>y;
  string a,b;
  cin>>a>>b;
  vector<int>vec;
  for(int i=0;i<n;i++){
	 if(a[i]!=b[i]){
		vec.push_back(i);
	 }
  }
  if(vec.empty()){
	cout<<0<<endl;
  }
  else if(vec.size()&1){
	cout<<-1<<endl;
  }
  else{
	 if(vec.size()>2){
		cout<<(vec.size()/2)*y<<endl;
	 }
	 else{
		if(vec[1]-vec[0]==1){
           if(2*y<=x){
		      cout<<2*y<<endl;  
		   }
		   else{
			cout<<x<<endl;
		   }
		}
		else{
           cout<<y<<endl;
		}
	 }
  }

}
void init(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
}
int32_t main(){
 //   init();
	int test;
	cin>>test;
	for(int i=1;i<=test;i++){
		solve(i);
	}
}/*
1
0
2
0 0
3
0 0 0
4
0 0 0 0
5
0 0 0 0 0
5
0 0 0 0 1
5
0 0 0 0 2
5
0 0 0 0 3
5
0 0 0 0 4
5
0 0 0 0 5
5
0 0 0 0 6
4
0 0 0 1
5
0 0 0 1 0
5
0 0 0 1 1
5
0 0 0 1 2
5
0 0 0 1 3
5
0 0 0 1 4
5
0 0 0 1 5
5
0 0 0 1 6
4
0 0 0 2
5
0 0 0 2 0
5
0 0 0 2 1
5
0 0 0 2 2
5
0 0 0 2 3
5
0 0 0 2 4
5
0 0 0 2 5
5
0 0 0 2 6
4
0 0 0 3
5
0 0 0 3 0
5
0 0 0 3 1
5
0 0 0 3 2
5
0 0 0 3 3
5
0 0 0 3 4
5
0 0 0 3 5
5
0 0 0 3 6
4
0 0 0 4
5
0 0 0 4 0
5
0 0 0 4 1*/