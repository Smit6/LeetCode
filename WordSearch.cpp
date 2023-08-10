// Time: O(N.3 ^ L) - L is the length of word and N is number of cells
// Space : O(L)

class Solution {
public:
    bool exist(vector<vector<char>>&, string);
private:
    int rows;
    int cols;
    unsigned int word_length;
    set<pair<int, int>> visited;

    bool dfs(vector<vector<char>>&, int, int, const string&, int);
};


bool Solution::exist(vector<vector<char>>& board, string word)
{
    rows = board.size();
    cols = board[0].size();
    word_length = word.length();

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (dfs(board, r, c, word, 0))
                return true;

    return false;
}

bool Solution::dfs(vector<vector<char>>& board, int r, int c, const string& word, int word_index)
{
    pair<int, int> rc(r, c);

    if (visited.find(rc) != visited.end() || word[word_index] != board[r][c])
        return false;

    if (word_index == word_length - 1)
        return true;

    visited.insert(rc);

    if (0 <= r - 1 && dfs(board, r - 1, c, word, word_index + 1)) return true;
    if (r + 1 < rows && dfs(board, r + 1, c, word, word_index + 1)) return true;
    if (0 <= c - 1 && dfs(board, r, c - 1, word, word_index + 1)) return true;
    if (c + 1 < cols && dfs(board, r, c + 1, word, word_index + 1)) return true;

    visited.erase(rc);

    return false;
}