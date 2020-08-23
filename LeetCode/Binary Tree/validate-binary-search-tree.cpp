#include "BinaryTree.h"
#include <stack>

class Solution {
public:
    bool solve(TreeNode *root, int &min, int &max) {
        if (!root->left && !root->right) {
            min = max = root->val;
            return true;
        }
        int lmi = INT_MAX, lma = INT_MIN;
        int rmi = INT_MAX, rma = INT_MIN;
        if (root->left) {
            if (solve(root->left, lmi, lma)) {
                printf("LEFT: %d:%d\n", lmi, lma);
                if (root->val <= lma || root->val <= lmi)
                    return false;
                else
                    min = lmi;
            } else {
                return false;
            }
        } else {
            min = root->val;
        }
        if (root->right) {
            if (solve(root->right, rmi, rma)) {
                printf("RIGHT: %d:%d\n", rmi, rma);
                if (root->val >= rmi || root->val >= rma)
                    return false;
                else
                    max = rma;
            } else {
                return false;
            }
        } else {
            max = root->val;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        int mi = INT_MAX, ma = INT_MIN;
        return solve(root, mi, ma);
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *>node;
        TreeNode *cur = root;
        int lastVal = INT_MIN;
        bool first = true;

        if (!root)
            return true;
        while (cur) {
            while (cur->left) {
                TreeNode *t = cur->left;
                cur->left = nullptr;
                node.push(cur);
                cur = t;
            }
            if (first)
                first = false;
            else if (lastVal >= cur->val)
                return false;
            lastVal = cur->val;
            if (cur->right) {
                cur = cur->right;
            } else {
                if (!node.empty()) {
                    cur = node.top();
                    node.pop();
                } else {
                    return true;
                }
            }
        }
        return true;
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *>node;
        int lastVal = INT_MIN;
        bool first = true;;

        while (!node.empty() || root) {
            while (root) {
                node.push(root);
                root = root->left;
            }
            root = node.top();
            node.pop();
            if (first)
                first = false;
            else if (lastVal >= root->val)
                return false;
            lastVal = root->val;
            root = root->right;
        }
        return true;
    }
};

int main(void) {
    vector<int> node = {2,1,3};
    TreeNode *root = buildTree(node);
    Solution s;
    bool ret = s.isValidBST(root);
    cout << "RET: " << ret << endl;

    return 0;
}