// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_validator bst_validator.cpp; ./bst_validator < bst_validator1.in

#include <iostream>
#include <sstream>
#include <vector>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;
/** QUESTION 4: BST VALIDATOR **/

// EFFECTS: Returns true if the tree is a valid BST, or false otherwise.
// 
// PSEUDOCODE:
// algorithm IsBST
//   Input: binary tree in vectorized form
//   Output: true or false value stating whether the binary search tree is valid or not
//   PSEUDOCODE
/*
      stack<int> st;
      i=0;
      while(i< binary_tree.size() or stack.empty()==False){
        while(i< binary_tree.size){
          st.push(i);
          i = 2*i+1;      // going to left subtree
        }
        root = binary_tree[st.top()]       //left_most node traversed
        i = st.top();
        st.pop();
//updating the previous value
        if(prev!=INT_MIN && root<=prev){
          return false;
        }
        prev = root;
        i = 2*i+2;          //traversing the right subtree
        if(i<binary_tree.size())
          root = binary_tree[i];
      }
      return true;
      }
*/
//
// COMMENTS:
/*
    1. Initialize a Stack to store the nodes along with its left subtree.
    2. Initialize a variable, say prev, to store previous visited node of the Binary Tree.
    3. Traverse the tree and push the root node and left subtree of each node into the stack
     and check if the data value of the prev node is greater than or equal to the data value of 
     the current visited node or not. If found to be true, then print “NO”.
    4. Otherwise, print “YES”.    
*/

bool IsBST(std::vector<int> &binary_tree) {
  // Implement this function.
  int i=0;int prev=INT_MIN;
  stack<int> st;
  int root = binary_tree[0];
  while(i<binary_tree.size() || !st.empty()){
    while(i<binary_tree.size()){
      st.push(i);
      i = 2*i+1;
    }
    root = binary_tree[st.top()];
    i = st.top();
    st.pop();

    if(prev!=INT_MIN && root<=prev){
      return false;
    }
    prev = root;
    i = 2*i+2;
    if(i<binary_tree.size())
      root = binary_tree[i];
  }
  return true;
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  std::vector<int> binary_tree;
  std::string input;
  getline(std::cin, input);
  std::stringstream iss(input);
  int number;
  while (iss >> number) {
    binary_tree.push_back(number);
  }
  if (IsBST(binary_tree)) {
    std::cout << "True";
  } else {
    std::cout << "False";
  }
  return 0;
}
