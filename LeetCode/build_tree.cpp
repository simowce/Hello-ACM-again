#include <math.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(vector<int> node) {
    TreeNode *root, *cur;
    int level = sqrt(node.size());
    for (int i=0; i<level; i++) {
        
    }
}