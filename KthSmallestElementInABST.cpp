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
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root)
            return 0;
        
        int kth = kthSmallest(root->left, k);
        if (kth)
            return kth;

        ++kth_smallest;
        if (kth_smallest == k)
            return root->val;

        kth = kthSmallest(root->right, k);
        if (kth)
            return kth;

        return 0;
    }
private:
    int kth_smallest = 0;
};