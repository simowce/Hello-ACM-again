/*
101. Symmetric Tree My Submissions QuestionEditorial Solution
Total Accepted: 101995 Total Submissions: 302646 Difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
// 一开始的做法是通过复制一棵镜像的树，然后来比较两棵树
// 后来发现很蠢，想到了另一种很巧妙的方法
// 每一个树都可以看作是根节点加上左右两个子树，所以，这两个子树是现成的，直接比较即可
// compare(a->left, b->right)
bool is_symm = true;

void compare(struct TreeNode *a, struct TreeNode *b)
{
    if ((a == NULL && b) || (a && b == NULL)) {
        is_symm = false;
        return ;
    }
    if (a == b && a == NULL)
        return ;
    if (a->val != b->val) {
        is_symm = false;
        return ;
    }
    compare(a->left, b->right);
    compare(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    is_symm = true;
    compare(root->left, root->right);
    return is_symm;
}
