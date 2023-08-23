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
    TreeNode* lowestCommonAncestor(TreeNode*, vector<TreeNode*>&);
private:
    set<TreeNode*> set_nodes;
    TreeNode* dfs(TreeNode*);
};

TreeNode* Solution::dfs(TreeNode* node) {
    if (!node || set_nodes.count(node))
        return node;
    auto l = dfs(node->left);
    auto r = dfs(node->right);
    if (l && r)
        return node;
    return l ? l : r;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
    set_nodes.insert(nodes.begin(), nodes.end());
    return dfs(root);
}
