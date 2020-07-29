```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans(TreeNode *root, int depth) {
        int l, r;
        if (!root) {
            return depth;
        }
        l = r = depth+1;
        if (root->left)
            l = ans(root->left, depth+1);
        if (root->right)
            r = ans(root->right, depth+1);
        return l > r ? l : r;
    }
    int maxDepth(TreeNode* root) {
        return ans(root, 0);
    }
};
```