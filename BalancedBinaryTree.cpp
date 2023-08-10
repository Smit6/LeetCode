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
    bool isBalanced(TreeNode*);
private:
    pair<int, bool> checkBalance(TreeNode*);
};

bool Solution::isBalanced(TreeNode* root)
{
    return checkBalance(root).second;
}

pair<int, bool> Solution::checkBalance(TreeNode* root)
{
    if (!root)
        return make_pair<int, bool>(0, true);

    pair<int, bool> left = checkBalance(root->left);
    if (!left.second)
        return left;
    pair<int, bool> right = checkBalance(root->right);
    if (!right.second)
        return right;

    return make_pair<int, bool>(1 + max(left.first, right.first), abs(left.first - right.first) <= 1);
}