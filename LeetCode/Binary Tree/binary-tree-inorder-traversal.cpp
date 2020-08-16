/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 迭代实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *>node;
        vector<int> ans;

        if (!root)
            return ans;
        node.push(root);
        while (!node.empty()) {
            TreeNode *t = node.top();
            while (t->left) {
                node.push(t->left);
                t->left = nullptr;
                t = node.top();
            }
            node.pop();
            ans.push_back(t->val);
            if (t->right)
                node.push(t->right);
        }

        return ans;
    }
};

// 递归实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        static vector<int> ans;
        if (!root)
            return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);

        return ans;
    }
};