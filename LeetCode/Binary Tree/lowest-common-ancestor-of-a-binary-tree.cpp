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
    bool findNode(TreeNode *cur, TreeNode *target, vector<TreeNode *>* store) {
        if (cur->val == target->val) {
            (*store).push_back(cur);
            return true;
        }
        if (cur->left && findNode(cur->left, target, store)) {
            (*store).push_back(cur);
            return true;
        }
        if (cur->right && findNode(cur->right, target, store)) {
            (*store).push_back(cur);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        vector<TreeNode *> llp, llq;
        int pi, qi;
        findNode(root, p, &llp);
        findNode(root, q, &llq);
        if (llp.size() > llq.size()) {
            pi = llp.size()-llq.size();
            qi = 0;
        } else {
            qi = llq.size()-llp.size();
            pi = 0;
        }
        while (pi < llp.size()) {
            if (llp[pi]->val == llq[qi]->val)
                return llp[pi];
            pi++;
            qi++;
        }
        return nullptr;
    }
};