// Time: O(N)
// Space: O(N)

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
    TreeNode* lowestCommonAncestor(TreeNode*, TreeNode*, TreeNode*);
private:
    tuple<bool, bool, TreeNode*> dfs(TreeNode*, TreeNode*, TreeNode*);
};

tuple<bool, bool, TreeNode*> Solution::dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
        return make_tuple(false, false, nullptr);
    
    auto left = dfs(root->left, p, q);
    if (get<2>(left))
        return left;
    
    auto right = dfs(root->right, p, q);
    if (get<2>(right))
        return right;
    
    bool p_found = get<0>(left) || get<0>(right) || p == root;
    bool q_found = get<1>(left) || get<1>(right) || q == root;

    if (p_found && q_found)
        return make_tuple(p_found, q_found, root);
    return make_tuple(p_found, q_found, nullptr);
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return get<2>(dfs(root, p, q));
}
