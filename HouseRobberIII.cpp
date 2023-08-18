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
    int rob(TreeNode*);
private:
    pair<int, int> dfs(TreeNode*);
};

pair<int, int> Solution::dfs(TreeNode* node) {
    if (!node)
        return make_pair(0, 0);
    
    auto left = dfs(node->left);
    auto right = dfs(node->right);

    int with_root = node->val + left.second + right.second;
    int without_root = max(left.first, left.second) + max(right.first, right.second);

    return make_pair(with_root, without_root);
}

int Solution::rob(TreeNode* root) {
    auto result = dfs(root);
    return max(result.first, result.second);
}