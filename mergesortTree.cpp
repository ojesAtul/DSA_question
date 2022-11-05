#include<bits/stdc++.h>
using namespace std;
#define mxSize 10001
class mergeSortTree{
  vector<int>tree[4*mxSize];
  vector<int>arr;
  void buildTree(int si,int ss,int se){
	 if(ss==se){
		tree[si].push_back(arr[ss]);
		return;
	 }
	 int mid=(ss+se)/2;
	 buildTree(2*si,ss,mid);
	 buildTree(2*si+1,mid+1,se);
	 int i=0,j=0;
	 while(i<tree[2*si].size() && j<tree[2*si+1].size()){
		if(tree[2*si][i]<=tree[2*si+1][j]){
			tree[si].push_back(tree[2*si][i++]);
		}
		else{
			tree[si].push_back(tree[2*si+1][j++]);
		}
	 }
	 while(i<tree[2*si].size() ){
		tree[si].push_back(tree[2*si][i++])
	 }
	 while(j<tree[2*si+1].size()){
        tree[si].push_back(tree[2*si+1][j++]);
	 }
  }
 int query(int si,int ss,int se,int qs,int qe,int val){
	if(qe<ss || se<qs){
		return 0;
	}
	else if(ss<=qs && qe<=se){
		return upper_bound(begin(tree[si]),end(tree[si]),val)-tree[si].begin(); 
 	}
	int mid=(ss+se)/2;
	return query(2*si,ss,mid,qs,qe,val)+query(2*si+1,mid+1,se,qs,qe,val);

 }
};