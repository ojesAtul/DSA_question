#include<bits/stdc++.h>
using namespace std;


// think also about it  iterative implemematation

/*
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
*/

struct node{
    int cnt;
    bool end;
    node* child[26];
    node(){
        cnt=0;
        end=false;
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
      {
        root->end=true;
        return;
      }
    if(root->child[str[pos]-'a']==NULL){
      root->child[str[pos]-'a']=new node();
      return insert_string(str,pos+1,root->child[str[pos]-'a']);
    }
    else{
        return insert_string(str,pos+1,root->child[str[pos]-'a']);
    }  
}
bool delete_string(string &str,int pos,node* root){
    if(!root){
        return false;
    }
    else if(pos==str.size()&&root->end==true){
       root->end=false;
       root->cnt--;
       return true;
    }
    bool flag=delete_string(str,pos+1,root->child[str[pos]-'a']);
    if(flag){
        root->cnt--;
    }
    // delete the node if cnt is zerro 
    if(root->child[str[pos]-'a']->cnt==0){
        node* temp=root->child[str[pos]-'a'];
        root->child[str[pos]-'a']=NULL;
        delete(temp);
    }

}
