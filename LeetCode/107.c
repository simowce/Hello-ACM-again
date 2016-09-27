/*
107. Binary Tree Level Order Traversal II My Submissions QuestionEditorial Solution
Total Accepted: 76126 Total Submissions: 226396 Difficulty: Easy
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
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
// 思路：
// 按照《编程之美》的思路，将树节点放置在一个数组里面，
// 先将根节点放置在数组的第一个位置，作为第一层
// 然后两个指针，cur 和 next_available ，cur 指针是当前层的迭代指针，当前层的范围是 cur 到 next_available 
// 遍历当前层，将当前层的所有节点找出来，存起来，并且找出当前层的左右子节点，加入数组，作为下一层
int cal_depth(struct TreeNode *t)
{
    if (t == NULL)
        return 0;
    
    int l = cal_depth(t->left) + 1;
    int r = cal_depth(t->right) + 1;
    
    return l > r ? l : r;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int depth = cal_depth(root);
    struct TreeNode *treenode[10000];
    int cur = 0;
    int next_available = 1;
    int cur_level_num;
    int i, j;
    int *tmp;
    int all_level = 0;
    int w = 1;
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
		// 当前层的范围：cur 到 cur_right，不包括 cur_right
        for (i = cur, j = 0; i < cur_right; i++) {
            tmp[j++] = (treenode[i])->val;
            if ((treenode[i])->left)
                treenode[next_available++] = (treenode[i])->left;
            if ((treenode[i])->right)
                treenode[next_available++] = (treenode[i])->right;
        }
        cur = i;
        (*columnSizes)[depth-w] = cur_level_num;
        ans[depth-w] = tmp;
        w++;
        //cur++;
    }
    return ans;
}
