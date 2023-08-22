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
    int maxPathSum(TreeNode*);
private:
    int max_sum = numeric_limits<int>::min();
    int dfs(TreeNode*);
};

int Solution::dfs(TreeNode* root) {
    if (!root)
        return 0;
    
    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);

    max_sum = max(max_sum, left + right + root->val);
    return max(left, right) + root->val;
}

int Solution::maxPathSum(TreeNode* root) {
    dfs(root);
    return max_sum;
}
