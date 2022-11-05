#include<bits/stdc++.h>
using namespace std;

// phone pay cash back

void phonepay_cashback(){
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);
	sum*=2;
	vector<int>dp(sum+1,0);
	dp[0]=1;

	for(int i=1;i<=sum;i++){
		bool flag=false;
		for(int j=0;j<n && arr[j]<=i;j++){
			if(dp[i-arr[j]]==1){
				dp[i]=1;
				flag=true;
				break;
			}
		}
		if(i>=arr[n-1] && !flag){
			cout<<i<<' '<<endl;
			return;
		}
	}
	cout<<-1<<endl;

}
#define lli long long int
n^4 implementaation 
int dp[101][101][2];
int jon_jade_fun(int l,int r,int turn,vector<int>&res,vector<int>&pref){
	if(l==r){
		return res[l];
	}
	else if(dp[l][r][turn]!=-1)
	  return dp[l][r][turn];
	  int ans=0;
	for(int i=l;i<=r;i++){
		if(i==l){
           int f1=fun(l+1,r,1-turn,res,pref);
		   int sum=pref[r]-pref[l];
		   int cur_ans=sum-f1;
		  ans=max(ans,cur_ans+res[i]); 
		}
		else if(i==r){
          int f1=fun(l,r-1,1-turn,res,pref);
		  int sum=pref[r-1];
		  if(l-1>=0){
             sum-=pref[l-1];
		  }  
		  int cur_ans=sum-f1;
		  ans=max(ans,cur_ans+res[i]);
		}
		else{
           int f1=fun(l,i-1,1-turn,res,pref);
		   int f2=fun(i+1,r,1-turn,res,pref);
		   int s1=pref[i-1];
		   if(l-1>=0)
		    s1-=pref[l-1];
           int s2=pref[r]-pref[i];
		   ans=max(ans,s1-f1+s2-f2+res[i]);
		}
	}  
  return dp[l][r][turn]=ans;
}
void  john_jade(){
   int n;
   cin>>n;
   int arr[n];
   int tt=0;
   for(int i=0;i<n;i++){
	  cin>>arr[i];
	  tt+=arr[i];
   }
   int ans=0;
   for(int i=0;i<n;i++){
	    vector<int>res;
		if(i==0){
           for(int j=1;j<n;j++){
			  res.push_back(arr[j]);
		   }
		}
		else if(i==n-1){
          for(int j=0;j<n-1;j++){
			  res.push_back(arr[j]);
		   }
		}
		else{
            for(int j=i-1;j>=0;j--){
				res.push_back(arr[j]);
			}
			for(int j=n-1;j>i;j--){
				res.push_back(arr[j]);
			}
		}
		vector<int>pref(begin(res),end(res));
		for(int j=1;j<n-1;j++){
			pref[j]+=pref[j-1];
		}
        for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				for(int l=0;l<2;l++){
					dp[j][k][l]=-1;
				}
			}
		}
    int cur=fun(0,n-2,0,res,pref);
	ans=max(ans,tt-cur); 
   }
   cout<<ans<<endl;
}

int arr[101];
int n;
int dp[101][101][2];
int arr[100001];
int pref[10001];
int jade_fun(int l,int r){
	 if(l==r){
		return res[l];
	 }
// dp state 


  int ans=0;
   if(l<=r){
	   for(int i=l;i<=r;i++){
		   if(i==l){
               int f1=jade_fun(l+1,r);
			   ans=max(ans,arr[i]+pref[r]-pref[l]-f1);
		   }
		   else if(i==r){
             int f1=jade_fun(l,r-1);
			 int s1=pref[r-1];
			 if(l-1>=0)
			 s1-=pref[l-1];
			 ans=max(ans,s1-f1+arr[i]);
		   }
		   else{
              int f1=jade_fun(l,i-1);
			  int f2=jade_fun(i+1,r);
			  int s1=pref[i-1];
			  if(l-1>=0)
			   s1-=pref[l-1];
              int s2=pref[r]-pref[i];


		   }
	   }
     
   

   }

   else{
   }

}


/// phone pay ipo just do the binay serach on the ans sort the array the fixed the differnece and check weather you can take the p element or not




void jon_jade(){
	int n;
	cin>>n;
	int tt=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
        tt+=arr[i];
 	}
    for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<2;k++)
			   dp[i][j][k]=-1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
         int l=(i+1)%n;
		 int r=(r-1+n)%n;
		 
	}

}




int main(){
	int t;
	cin>>t;
	while(t--){
		john_jade();
	}
}