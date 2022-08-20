#include<bits/stdc++.h>
using namespace std;
#define int long long int


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
class BinaryTree{
int cnt_of_node_in_substree(node* root){
    if(!root){
        return 0;
    }
    int lst=cnt_of_node_in_substree(root->left);
    int rst=cnt_of_node_in_substree(root->right);
    return 1+lst+rst;
}
int cnt_of_leaf(node* root){
    if(!root){
        return 0;
    }
    else if(!root->left&&!root->right){
        return 1;
    }
    int lst=cnt_of_leaf(root->left);
    int rst=cnt_of_leaf(root->right);
    return lst+rst;
}

};