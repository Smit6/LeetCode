/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return dfs(root, p, q).second;
    }
private:
    pair<pair<bool, bool>, TreeNode*> dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return make_pair(make_pair(false, false), nullptr);

        pair<pair<bool, bool>, TreeNode*> left = dfs(root->left, p, q);
        if (left.second)
            return left;
        pair<pair<bool, bool>, TreeNode*> right = dfs(root->right, p, q);
        if (right.second)
            return right;

        bool p_found = left.first.first || right.first.first || p == root;
        bool q_found = left.first.second || right.first.second || q == root;

        if (p_found && q_found)
            return make_pair(make_pair(p_found, q_found), root);
        return make_pair(make_pair(p_found, q_found), nullptr);
    }
};