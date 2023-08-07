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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;

        deque<TreeNode*> q({ root });
        int q_size = 1;

        vector<int> level;

        while (q.size())
        {
            q_size = q.size();
            level.clear();
            for (int i = 0; i < q_size; i++)
            {
                TreeNode* node = q.front();
                q.pop_front();
                level.push_back(node->val);
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
            result.push_back(level);
        }

        return result;
    }
};
