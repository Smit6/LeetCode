// Time: O(N^2)
// Space: O(N^2)

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>&);
private:
    pair<int, int> r_c_convert(int, int);
};

pair<int, int> Solution::r_c_convert(int n, int cols) {
    int r = (n - 1) / cols;
    int c = (n - 1) % cols;

    if (r % 2)
        c = cols - 1 - c;
    
    return make_pair(r, c);
}

int Solution::snakesAndLadders(vector<vector<int>>& board) {
    reverse(board.begin(), board.end());
    
    int rows = board.size();
    int cols = board[0].size();

    deque<pair<int, int>> q; // Square, moves
    q.push_back(make_pair(1, 0));
    set<int> visited; // Square
    int next_square = 0;

    while (q.size()) {
        auto& [square, moves] = q.front();
        q.pop_front();
        
        for (int i = 1; i < 7; i++) {
            next_square = square + i;
            auto [r, c] = r_c_convert(next_square, cols);

            if (board[r][c] != -1)
                next_square = board[r][c];
            if (next_square == rows * cols)
                return moves + 1;
            if (!visited.contains(next_square)) {
                visited.insert(next_square);
                q.push_back(make_pair(next_square, moves + 1));
            }
        }
    }

    return -1;
}
