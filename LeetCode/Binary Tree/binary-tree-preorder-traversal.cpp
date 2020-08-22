#define DEBUG
#ifdef DEBUG
#include <iostream>
#include "BinaryTree.h"
#endif

#include <stack>

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            stack<TreeNode *> rnode;
            vector<int> ans;
            TreeNode *cur = root;

            if (!root)
                return ans;
            while (cur) {
                ans.push_back(cur->val);
                if (cur->left) {
                    if (cur->right) {
                        rnode.push(cur->right);
                    }
                    cur = cur->left;
                } else if (cur->right) {
                    cur = cur->right;
                } else {
                    if (rnode.size()) {
                        cur = rnode.top();
                        rnode.pop();
                    } else {
                        cur = nullptr;
                    }
                }
            }
            return ans;
        }
};

#ifdef DEBUG
int main(void) {
    Solution s;

    vector<int> i = {1,2,3,4,null,5,6,7,8};
    TreeNode *root = buildTree(i);
    // cout << "PRINTING Tree..." << endl;
    // printTree(root);
    // cout << "\nPRINTED." << endl;
    vector<int> ret = s.preorderTraversal(root);
    cout << ret.size() << endl;
    for (int i:ret) {
        cout << i << " ";
    }
    destroyTree(root);

    return 0;
}
#endif