/*
102. Binary Tree Level Order Traversal My Submissions QuestionEditorial Solution
Total Accepted: 97815 Total Submissions: 301415 Difficulty: Easy
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 * */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cal_depth(struct TreeNode *t)
{
    if (t == NULL)
        return 0;
    
    int l = cal_depth(t->left) + 1;
    int r = cal_depth(t->right) + 1;
    
    return l > r ? l : r;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int depth = cal_depth(root);
    struct TreeNode *treenode[10000];
    int cur = 0;
    int next_available = 1;
    int cur_level_num;
    int i, j;
    int *tmp;
    int all_level = 0;
    int w = 0;
    int **ans = malloc(sizeof(int *) * depth);
    
    if (root == NULL)
        return NULL;
    *columnSizes = malloc(sizeof(int)*depth);
    treenode[0] = root;
    *returnSize = depth;
    while (cur != next_available) {
        cur_level_num = next_available-cur;
        tmp = malloc(sizeof(int)*cur_level_num);
        int cur_right = next_available;
        for (i = cur, j = 0; i < cur_right; i++) {
            tmp[j++] = (treenode[i])->val;
            if ((treenode[i])->left)
                treenode[next_available++] = (treenode[i])->left;
            if ((treenode[i])->right)
                treenode[next_available++] = (treenode[i])->right;
        }
        cur = i;
        (*columnSizes)[w] = cur_level_num;
        ans[w] = tmp;
        w++;
        //cur++;
    }
    return ans;
}
