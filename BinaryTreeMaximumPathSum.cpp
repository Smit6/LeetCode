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
class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        if (!root) return 0;
        max_sum = root->val;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum = 0;

    int dfs(TreeNode* node)
    {
        if (!node)
            return 0;
        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
        max_sum = max(max_sum, left + right + node->val);
        return max(left, right) + node->val;
    }
};