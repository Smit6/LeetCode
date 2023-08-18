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
    TreeNode* buildTree(vector<int>&, vector<int>&);
};


TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (!preorder.size())
        return nullptr;
    
    TreeNode* node = new TreeNode(preorder[0]);
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    int index = it - inorder.begin();

    vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + index + 1);
    vector<int> preorder_right(preorder.begin() + index + 1, preorder.end());
    vector<int> inorder_left(inorder.begin(), inorder.begin() + index);
    vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());

    node->left = buildTree(preorder_left, inorder_left);
    node->right=  buildTree(preorder_right, inorder_right);

    return node;
}
