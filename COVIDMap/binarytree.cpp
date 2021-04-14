/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include <vector>

using std::vector; 

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror_(root);
    
}

template <typename T>
void BinaryTree<T>::mirror_(Node *& node){
  if(node->left == NULL && node->right == NULL)
    return;
  
  Node * temp = node->right;
  node->right = node->left;
  node->left = temp;
  
  if(node->left != NULL)
    mirror_(node->left);
  if(node->right != NULL)
    mirror_(node->right);
  
  return;
}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    print();
    InorderTraversal<T> t(root);
    TreeTraversal<int>::Iterator it = t.begin();
    vector<Node *> list;
    
    while(it != t.end()){
      Node * newNode = *it;
      list.push_back(newNode);
      ++it;
    }
    for(unsigned int i = 0; i < list.size()-1; i++){
      Node * smallerNode = list[i];
      Node * largerNode = list[i+1];
      if(largerNode->elem < smallerNode->elem)
        return false;
    }
  
    return true;
}


/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    if(isOrderedRecursive_(root))
      return true;
    return false;
}

template<typename T>
bool BinaryTree<T>::isOrderedRecursive_(Node * currNode) const{
  
  if(currNode == NULL)
    return true;
  
  if(currNode->left != NULL){
    
    if(currNode->left->elem > currNode->elem)
      return false;
    
    if(currNode->left->right != NULL){
      if(currNode->left->right->elem > currNode->elem)
        return false;
    }
  }
  
  if(currNode->right != NULL){
    
    if(currNode->right->elem < currNode->elem)
      return false;
    
    if(currNode->right->left != NULL){
      if(currNode->right->left->elem < currNode->elem)
        return false;
    }
  }
  
  if(isOrderedRecursive_(currNode->left)==true && isOrderedRecursive_(currNode->right)==true)
    return true;
  return false;
  
  
}

