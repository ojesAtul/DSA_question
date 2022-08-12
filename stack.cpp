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

}