#include<bits/stdc++.h>
using namespace std;


struct node{
    char c;
    int freq;
    node* left;
    node* right;

    node(char c,int freq,node* left,node* right){
        this->c=c;
        this->freq=freq;
        this->left=left;
        this->right=right;
    }
};
class cmp{
    public:
    bool operator()(node* a,node* b){
       return a->freq>=b->freq;
    }
};


// let say we have two array a[],b[i]where a[i] is character and b[i] is the freq of character
void fun(vector<char>character,vector<int>freq,int n){
    priority_queue<node*,vector<node*> , cmp >pq;
    for(int i=0;i<n;i++){
        pq.push(new node(character[i],freq[i],NULL,NULL));
    }
  while(pq.size()>1){
    node* right=pq.top();
    pq.pop();
    node* left=pq.top();
    // now here we have to  create a new node and assgin their left and right 
    pq.pop();
    pq.push(new node(' ',left->freq+right->freq,left,right));
  }
}




