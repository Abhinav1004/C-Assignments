// Run in Repl.it
// clang++-7 -pthread -std=c++17 -o bst_depth bst_depth.cpp; ./bst_depth < bst_depth1.in

#include <iostream>
#include <sstream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
/** QUESTION 5: DEPTH AND PATH **/

// EFFECTS: Returns the depth of the target node. Modifies the path vector
//          so that it contains the node values in the path from the root to
//          the target node.
// 
// PSEUDOCODE:
// algorithm GetDepthAndPath
//   Input:  bst in vector form,target value to find, vector storing the path traversed
//            ,index position,depth till traversed
//   Output: 
//   updates  the path vector having the list of elements traversed
//   and returns the depth 
//    PSEUDOCODE
/*
      index=0;
      if(index>bst.size())
      return false;
      
      //updating the path vector with current value of bst
      path.push_back(bst[index]);       
      
      //if the current value is matched with the target value then return true
      if(bst[index] == target)
      return true;
      
      // traverse the left and right subtree recursively
      int left = 2*index+1;
      int right = 2*index+2;
        if(left<bst.size() && right<bst.size()){
            if(GetDepthAndPathUtil(bst,target,path,left,depth) || GetDepthAndPathUtil(bst,target,path,right,depth))
            depth+=1;
            return true;
          }

        path.pop_back();
        return false;     
*/
// COMMENTS:
/* we make a utils functions having the additional index value and depth which can update 
    themselves on every recursive call by the function
    starting from the root index we check for the target value 
    present in the left and right subtree
  if the value is matched 
      then the true value is returned and on each recursive call
      depth value is also incremented
*/

bool GetDepthAndPathUtil(vector<int> &bst,int target,vector<int> &path,int index,int& depth){
  if(index>bst.size())
  return false;
  path.push_back(bst[index]);

  if(bst[index] == target)
  return true;

  int left = 2*index+1;
  int right = 2*index+2;
    if(left<bst.size() && right<bst.size()){
        if(GetDepthAndPathUtil(bst,target,path,left,depth) || GetDepthAndPathUtil(bst,target,path,right,depth))
        depth+=1;
        return true;
      }

    path.pop_back();
    return false; 
}
int GetDepthAndPath(std::vector<int> &bst, int target, std::vector<int> &path) {
  // Implement this function.
  int depth = 0;
    GetDepthAndPathUtil(bst,target,path,0,depth);
  return depth;
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
  int target;
  std::cin >> target;
  
  std::vector<int> path;
  int depth = GetDepthAndPath(bst, target, path);

  std::cout << "depth = " << depth << std::endl;
  std::cout << "path = ";
  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i] ;
    if (i < path.size() - 1) {
      std::cout << " ";
    }
  }
  return 0;
}
