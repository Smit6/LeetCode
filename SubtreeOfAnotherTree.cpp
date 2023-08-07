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
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!subRoot)
            return true;
        if (!root)
            return false;

        if (compareTrees(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool compareTrees(TreeNode* node1, TreeNode* node2)
    {
        if (!node1 && !node2)
            return true;
        if ((node1 && !node2) || (!node1 && node2) || (node1->val != node2->val))
            return false;
        return compareTrees(node1->left, node2->left) && compareTrees(node1->right, node2->right);
    }
};
