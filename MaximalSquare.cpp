// Time: O(M * N)
// Space: O(M * N)

class Solution {
public:
    int maximalSquare(vector<vector<char>>&);
private:
    int rows, cols;
    map<pair<int, int>, int> cache;
    int dfs(vector<vector<char>>&, int, int);
};

int Solution::dfs(vector<vector<char>>& matrix, int r, int c) {
    auto rc = make_pair(r, c);
    int right, down, diag;
    if (cache.find(rc) == cache.end()) {
        right = c + 1 < cols ? dfs(matrix, r, c + 1) : 0;
        down = r + 1 < rows ? dfs(matrix, r + 1, c) : 0;
        diag = r + 1 < rows && c + 1 < cols ? dfs(matrix, r + 1, c + 1) : 0;
        cache[rc] = matrix[r][c] == '1' ? 1 + min({right, down, diag}) : 0;
    }
    return cache[rc];
}

int Solution::maximalSquare(vector<vector<char>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();

    dfs(matrix, 0, 0);

    int largest_square = 0;
    for (auto& [_, square] : cache)
        largest_square = max(largest_square, square);
    
    return largest_square * largest_square;
}
