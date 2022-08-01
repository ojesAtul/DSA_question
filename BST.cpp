// here i am going to create a binary 
#include<bits/stdc++.h>
using namespace std;
#define int long long int


/*

Inorder => Left, Root, Right.

Preorder => Root, Left, Right.

Post order => Left, Right, Root.

*/

struct node{
  int val;
  node* left;
  node* right;
  node(int v){
    val=v;
    left=NULL;
    right=NULL;
  }
};

// insertion function
void insert(int val,node* root){
    // i will do the iteration part
    node* cur=root;
   while(true){
        if(cur->val==val){
            return;
        }
        else if(cur->val<val){
          if(cur->right)
            cur=cur->right;
          else{
            cur->right=new node(val);
            return ;
          }  
        }
        else{
           if(cur->left)
             cur=cur->left;
           else{
              cur->left=new node(val);
              return ;
           }  
        }
   }
}

/// to find a val present into the BST
bool find(int val,node* root){
    node* cur=root;
    while(true){
        if(cur->val==val){
            return true;
        }
        else if(cur->val<val){
          if(cur->left)
            cur=cur->left;
          else
            return false;  
        }
        else{
          if(cur->right)
            cur=cur->right;
          else
            return false;   
        }
    }
    return false;
}

// inorder traversal
void inOrder(node* root){
   if(!root)
    return ;
   if(root->left)
     inOrder(root->left);
    cout<<root->val<<endl;
    if(root->right)
     inOrder(root->right);
}
// post order traveral 
void postOrder(node* root){
    if(!root)
     return;
    if(root->left)
      postOrder(root->left);
    if(root->right)
      postOrder(root->right);

    cout<<root->val<<endl;     
}  

// pre ordered traversal
void preOrder(node* root){
   if(!root)
     return;
   cout<<root->val<<endl;
   if(root->left)
   preOrder(root->left);
   if(root->right)
   preOrder(root->right);    
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    node* root=new node(arr[0]);
    for(int i=1;i<n;i++){
        insert(arr[i],root);
    }   
    // in order to chech BST use any or inorder or pre order or post order traversal
    inOrder(root);
    cout<<"here"<<endl;
    preOrder(root);
    cout<<"here"<<endl;
    postOrder(root);
    cout<<endl;
  
}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}
