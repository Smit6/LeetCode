// Time: O(N!)
// Space: O(N^2)

class Solution {
public:
    vector<vector<string>> solveNQueens(int);
private:
    set<int> pos_diag;
    set<int> neg_diag;
    set<int> cols;
    vector<string> board;
    vector<vector<string>> res;

    void backtrack(int, int);
};

void Solution::backtrack(int r, int n) {
    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if ((pos_diag.find(r + c) == pos_diag.end()) &&
            (neg_diag.find(r - c) == neg_diag.end()) &&
            (cols.find(c) == cols.end())) {
            pos_diag.insert(r + c);
            neg_diag.insert(r - c);
            cols.insert(c);

            board[r][c] = 'Q';

            backtrack(r + 1, n);

            pos_diag.erase(r + c);
            neg_diag.erase(r - c);
            cols.erase(c);

            board[r][c] = '.';
        }
    }
}

vector<vector<string>> Solution::solveNQueens(int n) {
    board.resize(n);
    string s(n,'.');
    for (int i = 0; i < n; i++)
        board[i] = s;

    backtrack(0, n);
    return res;
}
