#include<bits/stdc++.h>
using namespace std;
#define int  long long int

struct node{
    int val;
    node* left;
    node* right;
    node(){
        left=NULL;
        right=NULL;
    }
};
void inorder_itr(node* root){
    stack<pair<node*,int> >s;
    s.push(root);
    while(!s.empty()){
      pair<node*,int>cur=s.top();
      s.pop();
      if(cur.second==1){
         cout<<cur.first->val<<' ';
      }
      else{
         if(cur.first->right){
            s.push({cur.first->right,0});
         }
         s.push({cur.first,1});
         if(cur.first->left){
            s.push({cur.first->left,0});
         }
      }
    }
}

