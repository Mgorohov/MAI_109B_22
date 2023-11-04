#include "../include/Tree.hpp"


    Tree::Tree() : root(nullptr) {}
 
    void Tree::insert(int value) {
        root = insertRec(root, value);
    }
 
    void Tree::visualizeTree() {
        visualizeTreeRec(root, 0);
    }
 
    int Tree::findMaxLevel() {
        int maxLevel = 0;
        int maxCount = 0;
        findMaxLevelRec(root, 1, maxLevel, maxCount);
        return maxLevel;
    }
     
    
    TreeNode* Tree::insertRec(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
 
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value >= node->data) {
            node->right = insertRec(node->right, value);
        }
 
        return node;
    }
 
    void Tree::visualizeTreeRec(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
 
        visualizeTreeRec(node->right, depth + 1);
        cout << string(depth * 2, ' ') << node->data << endl;
        visualizeTreeRec(node->left, depth + 1);
    }
 
    void Tree::findMaxLevelRec(TreeNode* node, int level, int& maxLevel, int& maxCount) {
        if (node == nullptr) {
            return;
        }
 
        if (level > maxLevel) {
            maxLevel = level;
            maxCount = 1;
        } else if (level == maxLevel) {
            maxCount++;
        }
 
        findMaxLevelRec(node->left, level + 1, maxLevel, maxCount);
        findMaxLevelRec(node->right, level + 1, maxLevel, maxCount);
    }
    
