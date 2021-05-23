/*
 * autocomplete.cpp
 * 
 * The file where you will implement your autocomplete code for Project 4.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the autograder will fail. 
 */

#include "autocomplete.h"
#include<bits/stdc++.h>
using namespace std;
/** QUESTION 1: FINDNODE **/

// EFFECTS: Traverses the Tree based on the charactes in the prefix and 
//          returns the TreeNode that we end at. If we cannot find a valid node,
//          we return null. The index variable keeps track of what character we're
//          at in prefix.
// 
// PSEUDOCODE:
// algorithm FindNode
//   Input: Current Node,string prefix to search for,current index
//   Output: returns position of node after traversing the whole prefix string and returns null if
//        we cannot find a valid node 
//  PSEUDOCODE
/*
  if current value of node != prefix value at index i
      then
          return the node position i.e node
  else
      FindNode(node,prefix,index+1)   //for the next index position
*/
// COMMENTS:
/*
  if the prefix value at index position does not matches with node current value
  then the node current position is returned
  else the function recursively calls for next index position 
*/
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
  // Implement this function.
  if(prefix[index]!=node.GetValue())
      return TreeNode<char>(node);    
  else
    return FindNode(node,prefix,index+1);
}

/** QUESTION 2: COLLECTWORDS **/

// EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
//          prepends the word with the prefix and adds it to the results vector.
// 
// PSEUDOCODE:
// algorithm CollectWords
//   Input: Current Node position,string prefix,vector of strings
//   Output: vector of strings having collection of words from given node
//   PSEUDOCODE
/*
        if the current node is not empty
        then  
            prepend prefix to current node value
            append resultant string to vector of strings
            iterate recursively for all the children of the current node
                for appending to resultant vector of strings
*/
//
// COMMENTS:
/*
  we run collect_words recursively for including all combinations of 
  words formed from current node by iterating over all the children of the current node
*/
void CollectWords(TreeNode<char> node, std::string prefix, std::vector<std::string> &results) {
  // Implement this function.
    if(!node.IsEmpty()){
      prefix+=node.GetValue();
      results.push_back(prefix);
      for(int i=0;i<node.GetChildren().size();i++)
        CollectWords(node.GetChildren()[i],prefix,results);
    }
}

/** QUESTION 3: GETCANDIDATES **/

// EFFECTS: Returns the list of all possible words that can be made starting with
//          the letters in prefix, based on traversing the tree with the given root.
// 
// PSEUDOCODE:
// algorithm GetCandidates
//   Input: root node, and string prefix
//   Output: vector of string having all combinations of string autocomplete possible from the starting 
//        prefix
//   PSEUDOCODE
/*
      if the prefix is present in the branch of the starting root
        collect all possible words from it

      return the final resultant vector of string
*/
//
// COMMENTS:
/*
    We check first if the string prefix is present in the branch follwed by the root node
    if yes then we collect all possible words from it and append it to the resultant string vector 
    and return 
     
*/
std::vector<std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
  // Implement this function.
  vector<string> results; 
  if(!FindNode(root,prefix,0).IsEmpty()){
    CollectWords(root,prefix,results);
  }   
  return std::vector<std::string>(results);
}