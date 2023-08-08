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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty())
            return nullptr;

        TreeNode* node = new TreeNode(preorder[0]);
        
        vector<int>::iterator node_index_inorder_iterator = find(inorder.begin(), inorder.end(), preorder[0]);
        int node_index_inorder = node_index_inorder_iterator - inorder.begin();

        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + node_index_inorder + 1);
        vector<int> preorder_right(preorder.begin() + node_index_inorder + 1, preorder.end());
        vector<int> inorder_left(inorder.begin(), inorder.begin() + node_index_inorder);
        vector<int> inorder_right(inorder.begin() + node_index_inorder + 1, inorder.end());

        node->left = buildTree(preorder_left, inorder_left);
        node->right = buildTree(preorder_right, inorder_right);

        return node;
    }
};
