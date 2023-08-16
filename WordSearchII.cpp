// Time: O(M*(4*(3 ^ (L - 1)))) - M is the number of cells and L is the max length word
// Time: O(M*(3^L)) - Simply
// Space : O(N)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
};

class Solution {
public:
    Solution();
    vector<string> findWords(vector<vector<char>>&, vector<string>&);
private:
    int rows, cols;
    TrieNode* root;
    set<pair<int, int>> cycle;
    set<string> set_result;

    void add_word(const string&);
    void dfs(const vector<vector<char>>&, TrieNode*, string, int, int);
};

Solution::Solution() : root(new TrieNode())
{}

void Solution::add_word(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->children.find(c) == cur->children.end()) {
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
    }
    cur->is_end_of_word = true;
}

void Solution::dfs(const vector<vector<char>>& board, TrieNode* node, string cur_w, int r, int c) {
    pair<int, int> rc = make_pair(r, c);
    if (cycle.find(rc) != cycle.end() || node->children.find(board[r][c]) == node->children.end())
        return;

    cycle.insert(rc);

    node = node->children[board[r][c]];
    cur_w += board[r][c];

    if (node->is_end_of_word)
        set_result.insert(cur_w);

    if (0 <= r - 1) dfs(board, node, cur_w, r - 1, c);
    if (r + 1 < rows) dfs(board, node, cur_w, r + 1, c);
    if (0 <= c - 1) dfs(board, node, cur_w, r, c - 1);
    if (c + 1 < cols) dfs(board, node, cur_w, r, c + 1);

    cycle.erase(rc);
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {
    for (const string& word : words)
        add_word(word);

    rows = board.size();
    cols = board[0].size();

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            dfs(board, root, "", r, c);

    return vector<string>(set_result.begin(), set_result.end());
}
