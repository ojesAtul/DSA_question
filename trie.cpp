#include<bits/stdc++.h>
using namespace std;
struct node{
    int cnt;
    node* child[26];
    node(){
        cnt=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

int find_pref_cnt(string &str,int pos,node* root){
    if(!root)
      return 0;
    else if(pos==str.size())
    return root->cnt;
    return find_pref_cnt(str,pos+1,root->child[str[pos]-'a']);  
}

void insert_string(string &str,int pos,node* root){
    if(pos==str.size())
      return;
    if(root->child[str[pos]-'a']==NULL){
      root->child[str[pos]-'a']=new node();
      return insert_string(str,pos+1,root->child[str[pos]-'a']);
    }
    else{
        return insert_string(str,pos+1,root->child[str[pos]-'a']);
    }  
}
