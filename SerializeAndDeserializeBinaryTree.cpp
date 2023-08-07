/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root)
            return "NULL,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        data.pop_back();
        stringstream ss(data);
        vector<string> vals;
        string s;
        while (getline(ss, s, ','))
            vals.push_back(s);

        TreeNode* root = dfs_deserialize(vals);
        vals.clear();
        return root;
    }
private:
    int index = 0;

    TreeNode* dfs_deserialize(vector<string>& vals)
    {
        if (vals[index] == "NULL")
        {
            ++index;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[index]));
        ++index;
        node->left = dfs_deserialize(vals);
        node->right = dfs_deserialize(vals);
        return node;
    }
};
