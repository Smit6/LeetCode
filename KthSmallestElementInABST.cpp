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
    int kthSmallest(TreeNode*, int);
private:
    int smallest_index = 0;
};

int Solution::kthSmallest(TreeNode* root, int k) {
    if (!root)
        return 0;
    
    int kth = kthSmallest(root->left, k);
    if (!kth)
        return kth;

    ++smallest_index;
    kth = kthSmallest(root->right, k);
    if (!kth)
        return kth;

    return 0;
}
