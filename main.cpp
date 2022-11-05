#include<bits/stdc++.h>
using namespace std ;
#define end '\n'
#define mxSize 1000001

int get_first(int n){
	while(n>10){
		n/=10;
	}
	return n;
}
void solve(){
	long long n;
	cin>>n;
	int arr[n];
	vector<vector<long long>>dp(n,vector<int>(10,0LL));
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long ans=0;
    for(int i=0;i<n;i++){
		  int digit=get_first(arr[i]);
		  if(i==0){
			 dp[i][digit]=1;
			 continue;
		  }

		  for(int j=1;j<10;j++){
              if(dp[i-1][j]>0 && __gcd(j,arr[i]%10)==1)
			     ans+=dp[i-1][j];
		  }
		  dp[i][digit]++;
	}
	cout<<ans<<endl;
	
}

int isPrime[1000001];
void prime_sieve(){
	isPrime[0]=isPrime[1]=1;
	for(int i=2;i*i<=100000;i++){
		if(isPrime[i])
		  continue;
		for(int j=i*i;j<=100000;j+=i){
            isPrime[j]=1;
		}
	}
}

int cnt_prime[200001];
void sieve(){
	 for(int i=2;i<=200001;i++){
		 if(isPrime[i]==0){
		    cnt_prime[i]=1;
		    continue;
		 }
		 int sz=i;
		 for(int j=2;j*j<=sz;j++){
			  if(sz%j==0){
				cnt_prime[i]++;
				while(sz%j==0){
					sz/=j;
				}
			  }
		 }
		 if(sz>1){
			cnt_prime[i]++;
		 }
	 }
}
void large_fn(){
    int n,m;
	cin>>n>>m;
   int mn=min(n,m);
   int mx=max(n,m);
   int ans=0;
   for(int i=2;i<=n+m;i++){
	  int cnt=0;
	  if(i<=mn)
	    cnt=i-1;
      else if(<=mx){
		  cnt=mn;
	  }
	  else{
		  cnt=mn-i+mx;
	  }
	  ans+=cnt*cnt_prime[i];
   } 
   cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		prime_sieve();
		sieve();
		
	for(int i=0;i<=1000;i++){
		cout<<cnt_prime[i]<<' ';
	}	
	cout<<endl;
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}

}