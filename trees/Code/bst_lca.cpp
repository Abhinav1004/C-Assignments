// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_lca bst_lca.cpp; ./bst_lca < bst_lca1.in

#include <iostream>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
/** QUESTION 6: LOWEST COMMON ANCESTOR **/

// EFFECTS: Returns the value of the lowest common ancestor of nodes l and m.
// 
// PSEUDOCODE:
// algorithm GetLCA
//   Input: binary tree in vector form,value of two nodes
//   Output: value of the node which is a common parent i.e ancestor for both the nodes
//   PSEUDOCODE
/*
  if(bst[index]==l ||bst[index]==m){  //if the bst size is one i.e starting index 
                                            corresponds to both the nodes l and m,then return root node
    return bst[index];
  }
  int root = bst[index];
  unordered_map <int,int> parent;   //create a map for storing <node_value,index position>
  parent[root] = 0;               //root node has index position 0
  stack<int> st;                   // contains stack of index position visited
  st.push(0);

// pushing the parent of l and m with their index positions 

  while(!parent[l] ||!parent[m]){       
    int ind = st.top();st.pop();
    int left_index = 2*ind+1;
    int right_index = 2*ind+2;

    if(left_index < bst.size()){
      parent[bst[left_index]] = ind;
      st.push(left_index);
    }
    if(right_index < bst.size()){
      parent[bst[right_index]] = ind;
      st.push(right_index);
    }
  }

  //saving all the ancesotr of the l node into a set and finding the first occurence of the
  // common ancestor matching with m
  
  set<int> ancestor;          
  while(l){
    ancestor.insert(l);
    l = parent[l];
  }
  while(ancestor.find(m)==ancestor.end()){
    m = parent[m];
  }
  return bst[m];      
*/
//
// COMMENTS:
/*
The idea is to traverse through the tree until find both l and m, save (node, node's parent) 
during traversal, then save l's all ancestors into a set, check which m's ancestor is in that set,
 the first one will be the lowest common ancestor.
*/

int GetLCAUtil(vector<int> &bst,int l,int m,int index){
  if(bst[index]==l ||bst[index]==m){
    return bst[index];
  }
  int root = bst[index];
  unordered_map <int,int> parent;
  parent[root] = 0;
  stack<int> st;
  st.push(0);

  while(!parent[l] ||!parent[m]){
    int ind = st.top();st.pop();
    int left_index = 2*ind+1;
    int right_index = 2*ind+2;

    if(left_index < bst.size()){
      parent[bst[left_index]] = ind;
      st.push(left_index);
    }
    if(right_index < bst.size()){
      parent[bst[right_index]] = ind;
      st.push(right_index);
    }
  }
  set<int> ancestor;
  while(l){
    ancestor.insert(l);
    l = parent[l];
  }
  while(ancestor.find(m)==ancestor.end()){
    m = parent[m];
  }
  return bst[m];
}
int GetLCA(std::vector<int> &bst, int l, int m) {
  // Implement this function.
  int index=0;
  int lca = GetLCAUtil(bst,l,m,index);
  return lca;
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> bst;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    bst.push_back(number);
  }
  int l, m;
  std::cin >> l;
  std::cin >> m;
  
  std::vector<int> path;
  int lca = GetLCA(bst, l, m);

  std::cout << "lca = " << lca;
  return 0;
}
