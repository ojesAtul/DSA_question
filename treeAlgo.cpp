#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node* left;
  node* right;
  node(){
	left=NULL;
	right=NULL;
  }
};
void mirror_image(node* root){
	if(!root){
		return;
	}
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
	mirror_image(root->left);
	mirror_image(root->right);
}
bool isSymmetric(node* tree1,node* tree2){
	if(!tree1 && !tree2)
	return true;
	else if(!tree1){
	return false;
	}  
	else if(!tree2)
	return false;
	else if(tree1->val!=tree2->val)
		return false;
	return isSymmetric(tree1->left,tree2->right)&&isSymmetric(tree1->right,tree2->left); 
}
bool symmetricBinarytree(node* root){
	if(!root)
		return true;
	return isSymmetric(root->left,root->right);  
}