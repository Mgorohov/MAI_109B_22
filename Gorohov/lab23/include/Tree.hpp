#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "../include/Node.hpp"

#include <iostream>
#include <string>
 
class Tree {
private:
    TreeNode* root;
 
public:
    Tree();
 
    void insert(int value); 
 
    void visualizeTree(); 
 
    int findMaxLevel(); 
 
private:
    TreeNode* insertRec(TreeNode* node, int value); 
 
    void visualizeTreeRec(TreeNode* node, int depth);
 
    void findMaxLevelRec(TreeNode* node, int level, int& maxLevel, int& maxCount); 
};
 
#include "../src/Tree.cpp"

#endif

