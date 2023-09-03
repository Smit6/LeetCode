// Time: O(min(N1, N2)), where N1, N2 are the lengths of root1 and root2
// Space: O(min(H1, H2)), where H1, H2 are the heights of root1 and root2

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
    bool flipEquiv(TreeNode*, TreeNode*);
};


bool Solution::flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return true;
    
    if ((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
        return false;
    
    return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
}
