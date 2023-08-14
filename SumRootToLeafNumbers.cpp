// Time: O(N)
// Space: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode*);
private:
    int dfs(TreeNode*, int);
};

int Solution::sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int Solution::dfs(TreeNode* node, int num) {
    if (!node)
        return 0;
    num = (num * 10) + node->val;
    if (!node->left && !node->right)
        return num;
    return dfs(node->left, num) + dfs(node->right, num);
}
