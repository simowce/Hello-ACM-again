/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 思路：
// 计算左右子树的高度，然后计较高度差，如果大于 1 ，那么就设置全局标识变量，最后在主调用函数直接返回即可
bool not_balance = false;

int cal_height(struct TreeNode *t)
{
    if (t == NULL)
        return 0;
    
    int l = cal_height(t->left) + 1;
    int r = cal_height(t->right) + 1;
    if (l-r > 1 || r-l >1)
        not_balance = true;
    else
        return l > r ? l : r;
}
bool isBalanced(struct TreeNode* root) {
    not_balance = false;
    cal_height(root);
    return !not_balance;
}
