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
    bool isValidBST(TreeNode* root)
    {
        return dfs(root, nullptr, nullptr);
    }
private:
    bool dfs(TreeNode* node, TreeNode* min_limit, TreeNode* max_limit)
    {
        if (!node)
            return true;

        if ((min_limit && node->val <= min_limit->val) || (max_limit && node->val >= max_limit->val))
            return false;
        
        return dfs(node->left, min_limit, node) && dfs(node->right, node, max_limit);
    }
};
