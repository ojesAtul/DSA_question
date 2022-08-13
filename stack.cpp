#include<bits/stdc++.h>
using namespace std;
// my own stack class
class Stack{
private:
    vector<int>vec;
public:
    void Push(int num){
        vec.push_back(num);
    }
    bool Empty(){
        return vec.empty();
    }
    int Top(){
      if(Empty()){
        exit(0);
      }
      return vec.back();
    }
    void Pop(){
        if(Empty())
         exit(0);
        vec.pop_back(); 
    }
};
// implement two stack into the same array
class toStack{
private:
    int arr[10000];
    int left=-1,right=10000;
public:    
    void push1(int val){
        if(left+1==right){
            exit(0);
        }
        arr[++left]=val;
    }
    void push2(int val){
        if(right-1==left)
         exit(0);
        arr[--right]=val; 
    }
    void pop1(){
        if(left==-1){
            exit(0);
        }
        left--;
    }
    void pop2(){
        if(right==10000){
            exit(0);
        }
        right++;
    }
    int top1(){
        if(left==-1)
          exit(0);
        return arr[left];  
    }
    int top2(){
        if(right==10000)
           exit(0);
        return arr[right];   
    }
   int sizeOf(){
    return left+1+10000-right;
   }
};

void pushBottom(stack<int>&s,int &val){
    if(s.empty()){
       s.push(val);
       return;
    }
    int Top=s.top();
    s.pop();
    pushBottom(s,val);
    s.push(Top);

}
void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int topEL=s.top();
    s.pop();
    reverseStack(s);
    pushBottom(s,topEL);
}

