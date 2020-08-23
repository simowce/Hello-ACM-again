1. [中序遍历](1)

    递归的实现很简单，这里主要描述一下迭代的实现。
    中序遍历因为会一直先处理 left 节点，所以其实整体的迭代流程类似一个栈
    迭代的流程分为三步：
    1. 如果有 left 节点就一直将 left push 到栈中（注意将 left 节点 push 到栈中以后，需要将当前节点跟 left 节点切断，否则会死循环）
    2. 没有 left 节点了，当前节点出栈，并且将 val push_back 到 vector
    3. 如果有 right 节点，入栈

    如此循环，循环的退出条件是栈为空。

    一开始写的时候超时了，是因为节点 push 到栈以后，没有将 left 给切断，导致死循环（因为中序的是一直找到那么没有 left 子节点以后才会停止，没有切断 left 的话就会导致死循环）

    看了一下官方的题解发现一种更加优雅的实现，我的这种实现其实会破坏原来的二叉树，但是官方的实现就不会破坏，它的做法是：
    1. 跟我的

2. [前序遍历](6)

    迭代的实现思路是：使用一个栈保留当前的节点的右节点。
    更新当前节点的逻辑是：
    * 当前节点有 left：right(如果有) 保留到栈中，cur = cur->left
    * 当前节点只有 right：cur = cur->right
    * 没有 left 和 right：栈顶节点作为 cur，如果栈为空，说明遍历完成

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
        vector<int> preorderTraversal(TreeNode* root) {
            // 这个是一个暂存的地方
            stack<TreeNode *> node;
            vector<int> ans;
            TreeNode *cur = root;

            if (!root)
                return ans;
            while (cur) {
                ans.push_back(cur->val);
                if (cur->left) {
                    if (cur->right)
                        node.push(cur->right);
                    // 这里需要注意，要把 right 保存以后再修改 cur
                    // 因为写反了导致这里卡了好久好久
                    cur = cur->left;
                } else if (cur->right) {
                    cur = cur->right;
                } else {
                    if (!node.empty()) {
                        cur = node.top();
                        node.pop();
                    } else {
                        cur = nullptr;
                    }
                }
            }
            return ans;
        }
    };
    ```

3. [二叉树的后序遍历](7)

4. [二叉树的最近公共祖先](2)

    一开始的思路是，将二叉树转换为堆（用一个数组去实现），然后在遍历，转换的过程中，如果找到目标节点则记下 index（是堆中的 index，表现形式为，left = cur*2, right = cur*2+1），然后两个在一直除以二知道两边相等即是最近公共祖先。
    仔细思考后发现不行，堆的空间是指数级别。

    然后按照这个堆的思路，可以想象一下，如果将两个目标节点经过的树节点分别有两个线连起来，如下图：

    就可以将问题转换为两个相交链表的第一个公共节点，并且这里不需要用链表表示，直接用 vector 即可。
    因此用递归找到两个目标节点经过的树节点分别填充到两个 vector，接着按照相交链表的思路，砍掉长链表的部分，然后一个一个比较即可

    TODO: 搜索写法

5. [二叉树层序遍历](3)
    思路是利用队列。
    有几个变种：
    * [二叉树层序遍历2](4)
       将输出修改为每层一个独立 vector，需要对每一层都进行单独处理：
       有两种处理方式，一种是将所有树节点都放到一个 vector 里，然后使用两个下标 si 和 ei 圈起作为当前层的左闭右开区间
       但是这样有个问题就是空间浪费，每一层用完以后其实就没用了，但是 vector 依旧会存起来。

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
            vector<vector<int>> levelOrder(TreeNode* root) {
                vector<TreeNode *> node;
                vector<vector<int>> ans;
                int si = 0, ei = 1;

                if (!root)
                    return ans;
                node.push_back(root);
                do {
                    vector<int> tmp;
                    for (int i=si; i<ei; i++) {
                        tmp.push_back(node[i]->val);
                        if (i==si)
                            si = node.size();
                        if (node[i]->left)
                            node.push_back(node[i]->left);
                        if (node[i]->right)
                            node.push_back(node[i]->right);
                    }
                    ei = node.size();
                    ans.push_back(tmp);
                } while (si != ei);
                return ans;
            }
        };
        ```

        第二种思路是将当前层用一个 queue 来存储，这样的好处是解决了 vector 空间浪费的问题，这个 queue 只存储当前层。
        如何做到只处理当前层，**每次开始处理的时候，记录一下当前 queue 的 size，然后只处理 `size()` 次**，这样就达到了只处理当前层的效果了。

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
            vector<vector<int>> levelOrder(TreeNode* root) {
                queue<TreeNode *> node;
                vector<vector<int>> ans;

                if (!root)
                    return ans;
                node.push(root);
                while (!node.empty()) {
                    // 这一行是重点，只处理当前层的重点
                    int c = node.size();
                    vector<int> tmp;
                    while (c--) {
                        TreeNode *cur = node.front();
                        node.pop();
                        tmp.push_back(cur->val);
                        if (cur->left)  node.push(cur->left);
                        if (cur->right) node.push(cur->right);
                    }
                    ans.push_back(tmp);
                }
                return ans;
            }
        };
        ```

        代码很明显就简洁了很多了。

6. [二叉树的锯齿状层次遍历](5)
7. [验证二叉搜索树](7)
    注意一个正确的二叉搜索树应该满足：
    * 节点的左子树只包含小于当前节点的数。
    * 节点的右子树只包含大于当前节点的数。
    * 所有左子树和右子树自身必须也是二叉搜索树

    注意，由于修改了函数参数中的 min 和 max，因此 `solve()` 中这两个参数应该声明为引用或者指针。

    ```cpp
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
        if (!root)
            return true;
        return solve(root, mi, ma);
    }
    };
    ```

    但是这个实现空间占用太大了，有一个更加优雅的实现，俺就是利用**一个搜索二叉树的中序遍历就是一个单调递增序列**，判断前后两个节点的值是否满足这个条件即可：
    注意：要处理好节点值为 `INT_MIN` 的 case，因为一开始我是用 `INT_MIN` 来初始化 `lastVal` 的，但是在 `if (lastVal >= cur->val) return false` 的判断中，如果 `cur->val==INT_MIN`， 此时就会出问题。
    因此引入了一个 `first` 标记，第一次不去做比较：

    ```cpp
    class Solution {
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
    ```

[1][https://leetcode-cn.com/problems/binary-tree-inorder-traversal]
[2][https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/]
[3][https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/]
[4][https://leetcode-cn.com/problems/binary-tree-level-order-traversal/]
[5][https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/]
[6][https://leetcode-cn.com/problems/binary-tree-preorder-traversal/]
[7][https://leetcode-cn.com/problems/validate-binary-search-tree/]