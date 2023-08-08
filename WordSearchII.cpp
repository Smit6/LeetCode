class TrieNode
{
public:
    map<char, TrieNode*> children;
    bool is_end_of_word = false;
};

class Solution
{
public:
    Solution()
    {
        root = new TrieNode();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        rows = board.size();
        cols = board[0].size();

        for (auto& word : words)
            add_word(word);

        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
            {
                dfs(r, c, board, root, "");
            }

        vector<string> result(res.begin(), res.end());
        return result;
    }
private:
    TrieNode* root;

    set<string> res;
    set<pair<int, int>> cycle;

    int rows;
    int cols;

    void add_word(string& word)
    {
        TrieNode* cur = root;
        
        for (auto& c : word)
        {
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }

        cur->is_end_of_word = true;
    }

    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node, string cur_word)
    {
        pair<int, int> rc(r, c);

        if ((node->children.find(board[r][c]) == node->children.end()) || (cycle.find(rc) != cycle.end()))
            return;

        cycle.insert(rc);

        node = node->children[board[r][c]];
        cur_word += board[r][c];

        if (node->is_end_of_word)
            res.insert(cur_word);

        if (0 <= r - 1)
            dfs(r - 1, c, board, node, cur_word);
        if (r + 1 < rows)
            dfs(r + 1, c, board, node, cur_word);
        if (0 <= c - 1)
            dfs(r, c - 1, board, node, cur_word);
        if (c + 1 < cols)
            dfs(r, c + 1, board, node, cur_word);

        cycle.erase(rc);
    }
};