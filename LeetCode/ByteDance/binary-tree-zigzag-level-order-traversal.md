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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool reverse = false;
        vector<vector<int>> ans;      

        // 没想到居然可以 push NULL
        stack<TreeNode *> container;
        if (root)
            container.push(root);
        else
            return ans;

        while (!container.empty()) {
            int c = container.size();
            vector<int> tv;
            vector<TreeNode *> tmp;
            for (int i=0; i<c; i++) {
                tmp.push_back(container.top());
                container.pop();
            }
            for (int i=0; i<tmp.size(); i++) {
                TreeNode *t = tmp[i];
                tv.push_back(t->val);
                if (reverse) {
                    if (t->right)   container.push(t->right);
                    if (t->left)    container.push(t->left);
                } else {
                    if (t->left)    container.push(t->left);
                    if (t->right)   container.push(t->right);
                }
            }
            ans.push_back(tv);
            reverse = !reverse;
        }
        return ans;
    }
};
```

我的做法是：

首先将每一层的所有节点加入到一个 stack（为什么是 stack 呢？是因为他先入后出的特性，跟本题 zigzag 是一致的）
然后将 stack pop 到一个 vector，然后根据这个 vector
// TODO
// 写不下去了，这道题目能够完全是瞎改出来的，我自己都说不出为什么出来，需要重写