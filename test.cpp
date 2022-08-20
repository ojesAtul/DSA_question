#include<bits/stdc++.h>
using namespace std;
#define int long long int 

bool cmp(int a,int b){
    return a%10<=b%10;
}

vector<int>row,col;
int cntBit(int num){
    int cnt=0;
    while(num>0){
        if(num&1)
        cnt++;
        num/=2;
    }
    return cnt;
}
void init(int r1,int c1,int r2,int c2){
    r1=(1<<r1);
    c1=(1<<c1);
    for(int i=1;i<r1;i++){
        if(cntBit(i)==r2)
          row.push_back(i);
    }
    for(int i=1;i<c1;i++){
        if(cntBit(i)==c2){
            col.push_back(i);
        }
    }

}
void solve(){
   int n,m;
   cin>>n>>m;
   int a[n][m];
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>a[i][j];
      }
   }
   int newn,newm;
   cin>>newn>>newm;
   vector<vector<int>>b(newn,vector<int>(newm,0));
  for(int i=0;i<newn;i++){
    for(int j=0;j<newm;j++)
    cin>>b[i][j];
  }
  init(n,m,newn,newm);
  

    for(auto x:row){
    for(auto y:col){
       vector<vector<int>>vec;
       for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            if((x&(1<<i))&&(y&(1<<j)))
              temp.push_back(a[i][j]);
        }
        vec.push_back(temp);
       }
       for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++)
          cout<<vec[i][j]<<' ';
          cout<<endl;
       }
       
       bool f=true;/*
       for(int i=0;i<newn;i++){
        for(int j=0;j<newm;j++){
            if(vec[i][j]!=b[i][j]){
                f=false;
                break;
            }
        }
       }
       if(f){
        cout<<"Yes"<<endl;
        return;
       }*/
    }
  }
  cout<<"No"<<endl;

}
int32_t main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
