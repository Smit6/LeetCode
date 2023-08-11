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
    TreeNode* sortedArrayToBST(vector<int>&);
private:
    TreeNode* convertSortedArrayToBST(vector<int>&, int, int);
};

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    return convertSortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode* Solution::convertSortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right)
        return nullptr;
    int mid = left + ((right - left) / 2);

    TreeNode* num_node = new TreeNode(nums[mid]);
    num_node->left = convertSortedArrayToBST(nums, left, mid - 1);
    num_node->right = convertSortedArrayToBST(nums, mid + 1, right);
    return num_node;
}
