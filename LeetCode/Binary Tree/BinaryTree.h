#ifndef _LEETCODE_BINARY_TREE_H_
#define _LEETCODE_BINARY_TREE_H_

#include <vector>
#include <limits>
#include <iostream>

#define null INT_MIN

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> node);
void printTree(TreeNode *root);
void destroyTree(TreeNode *root);

#endif