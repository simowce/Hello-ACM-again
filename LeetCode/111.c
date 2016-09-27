/*
111. Minimum Depth of Binary Tree My Submissions QuestionEditorial Solution
Total Accepted: 101166 Total Submissions: 331465 Difficulty: Easy
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 思路：
// 按照求最大深度的思路来，不过这里有一个点，
// **题目要求的是要叶节点到根节点的最短距离，也就是说，如果根节点的某个儿子为空，这个是不算的**
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    int l = 99999999, r = 99999999;
    if (root->left)
        l = minDepth(root->left) + 1;
    if (root->right)
        r = minDepth(root->right) + 1;
    
    return l < r ? l : r;
}
