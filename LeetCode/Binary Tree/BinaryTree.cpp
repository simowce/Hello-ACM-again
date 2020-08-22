#include <iostream>

#include <math.h>
#include <cstdio>

#include "BinaryTree.h"

TreeNode *buildTree(vector<int> valueList) {
    TreeNode *root;
    int level = log(valueList.size())/log(2);
    vector<TreeNode *> treeNode;

    if (!valueList.size())
        return nullptr;
    root = new TreeNode(valueList[0]);
    // for convient
    treeNode.push_back(nullptr);
    treeNode.push_back(root);
    for (int l=1; l<=level; l++) {
        // printf("LEVEL: %d/%d\n", l, level);
        for (int i=(1<<l)-1; i<(1<<l+1)-1 && i<valueList.size(); i++) {
            // cout << "VALUE: " << valueList[i] << " " << endl;
            TreeNode *t;
            if (valueList[i] == null)
                t = nullptr;
            else
                t = new TreeNode(valueList[i]);
            TreeNode *parent = treeNode[(i+1)/2];
            assert(parent);
            cout << "PARENT: " << parent->val << endl;
            if (i%2)
                parent->left= t;
            else
                parent->right= t;
            treeNode.push_back(t);
        }
    }

    return root;
}

void printTree(TreeNode *root) {
    if (!root)
        return ;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

void destroyTree(TreeNode *root) {
    if (!root)
        return ;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}