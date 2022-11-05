#include <bits/stdc++.h>
using namespace std;

#define mxSize 100001
class segmentTree{
public:	
int arr[mxSize],segtree[mxSize];
void buildTree(int si,int ss,int se){
	if(ss==se){
		segtree[si]=arr[ss];
		return;
	}
	int mid=(ss+se)/2;
	buildTree(2*si,ss,mid);
	buildTree(2*si+1,mid+1,se);
	segtree[si]=min(segtree[2*si],segtree[2*si+1]);
}
int query(int si,int ss , int se,int qs,int qe){
	if(qs>se || qe<ss)
	 return INT_MIN;
	else if(ss<=qs && qe <= se)
	  return segtree[si]; 	
    int mid=(ss+se)/2;
	return min(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
}
void pointUpdate(int si,int ss,int se,int qi){
	if(ss==se){
		segtree[si]=arr[ss];
		return;
	}
	if(qi< ss || qi>se){
		return;
	}
	int mid=(ss+se)/2;
	if(qi<=mid){
		pointUpdate(2*si,ss,mid,qi);
	}
	else{
		pointUpdate(2*si+1,mid+1,se,qi);
	}
	segtree[si]=min(segtree[2*si],segtree[2*si+1]);
}
};

class lazySegmenttree{
  public:
  int arr[mxSize];
  int tree[mxSize];
  int lazytree[4*mxSize];
  void buildTree(int si,int ss , int se){
     if(ss==se){
		tree[si]=arr[si];
		return;
	 }
	 int mid=(ss+se)/2;
	 buildTree(2*si,ss,mid);
	 buildTree(2*si+1,mid+1,se);
	 tree[si]=tree[2*si]+tree[2*si+1];
  }
  int query(int si,int ss,int se,int qs,int qe){
    // this is extra code of past first i have to perform
	if(lazytree[si]!=0){
		int dx=lazytree[si];
		lazytree[si]=0;
		tree[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazytree[2*si]+=dx;
			lazytree[2*si+1]+=dx;
		}
	}
	 if(ss==se){
		return tree[si];
	 }
	 else if(qe<ss || se<qs )
	  return 0;
	 else if(ss<=qs && qe<=se){
		return tree[si];
	 } 
     int mid=(ss+se)/2;
	 return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
  }
  void lazyUpdate(int si,int ss,int se,int qs,int qe,int val){
      if(lazytree[si]!=0){
		int dx=lazytree[si];
		lazytree[si]=0;
		tree[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazytree[2*si]+=dx;
			lazytree[2*si+1]+=dx;
		}
	}
   if(qe<ss || se<qs){
      return ;
   }
   else if(ss<=qs && qe<=se){
	  int dx=(se-ss+1)*val;
	  tree[si]+=dx;
	  if(ss!=se){
		lazytree[2*si]+=val;
		lazytree[2*si+1]+=val;
		return;
	  }
   }
   int mid=(ss+se)/2;
   lazyUpdate(2*si,ss,mid,qs,qe,val);
   lazyUpdate(2*si+1,mid+1,se,qs,qe,val);
   tree[si]=tree[2*si]+tree[2*si+1];
  }
};

int main()
{
   int t;
   cin>>t;
   // do check the seqment tree
}