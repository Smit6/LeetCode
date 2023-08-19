// Time: O(R*C)
// Space: O(R*C)

class Solution {
public:
    void solve(vector<vector<char>>&);
private:
    int rows, cols;
    void dfs(vector<vector<char>>&, int, int);
};

void Solution::dfs(vector<vector<char>>& board, int r, int c) {
    board[r][c] = 'S';

    if (0 <= r - 1 && board[r - 1][c] == 'O')
        dfs(board, r - 1, c);
    if (r + 1 < rows && board[r + 1][c] == 'O')
        dfs(board, r + 1, c);
    if (0 <= c - 1 && board[r][c - 1] == 'O')
        dfs(board, r, c - 1);
    if (c + 1 < cols && board[r][c + 1] == 'O')
        dfs(board, r, c + 1);
}

void Solution::solve(vector<vector<char>>& board) {
    rows = board.size();
    cols = board[0].size();

    for (int r = 0; r < rows; r++) {
        if (board[r][0] == 'O')
            dfs(board, r, 0);
        if (board[r][cols - 1] == 'O')
            dfs(board, r, cols - 1);
    }
    
    for (int c = 0; c < cols; c++) {
        if (board[0][c] == 'O')
            dfs(board, 0, c);
        if (board[rows - 1][c] == 'O')
            dfs(board, rows - 1, c);
    }

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (board[r][c] == 'O')
                board[r][c] = 'X';
            else if (board[r][c] == 'S')
                board[r][c] = 'O';
}
