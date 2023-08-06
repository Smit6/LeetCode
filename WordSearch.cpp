class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        rows = board.size(), cols = board[0].size();
        word_size = word.size();
        
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (dfs(board, word, 0, r, c))
                    return true;

        return false;
    }
private:
    int rows, cols;
    int word_size = 0;
    set<pair<int, int>> cycle;

    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c)
    {
        pair<int, int> rc(r, c);
        if (cycle.find(rc) != cycle.end() || board[r][c] != word[i])
            return false;
        if (i == word_size - 1)
            return true;
        cycle.insert(rc);

        if (0 <= r - 1 && dfs(board, word, i + 1, r - 1, c))
            return true;
        if (r + 1 < rows && dfs(board, word, i + 1, r + 1, c))
            return true;
        if (0 <= c - 1 && dfs(board, word, i + 1, r, c - 1))
            return true;
        if (c + 1 < cols && dfs(board, word, i + 1, r, c + 1))
            return true;
        
        cycle.erase(rc);

        return false;
    }
};
