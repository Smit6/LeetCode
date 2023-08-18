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
    vector<vector<int>> levelOrder(TreeNode*);
};

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    if (!root)
        return levels;

    deque<TreeNode*> q;
    q.push_back(root);

    int q_size = 0;

    while (q.size()) {
        q_size = q.size();
        vector<int> level;
        for (int i = 0; i < q_size; i++) {
            TreeNode* node = q.front();
            q.pop_front();

            level.push_back(node->val);
            if (node->left)
                q.push_back(node->left);
            if (node->right)
                q.push_back(node->right);
        }
        levels.emplace_back(move(level));
    }

    return levels;
}
