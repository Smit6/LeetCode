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
    vector<int> rightSideView(TreeNode*);
};

vector<int> Solution::rightSideView(TreeNode* root) {
    if (!root)
        return vector<int>();

    vector<int> result;
    deque<TreeNode*> q;
    int q_size = 0;
    TreeNode* cur_node;

    q.push_back(root);

    while (!q.empty()) {
        q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            cur_node = q.front();
            q.pop_front();

            if (cur_node->left)
                q.push_back(cur_node->left);

            if (cur_node->right)
                q.push_back(cur_node->right);

            if (i == q_size - 1)
                result.push_back(cur_node->val);
        }
    }

    return result;
}
