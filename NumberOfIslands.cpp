class Solution {
public:
    int numIslands(vector<vector<char>>&);
private:
    int rows, cols;
    void dfs(vector<vector<char>>&, int, int);
};

int Solution::numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    rows = grid.size();
    cols = grid[0].size();

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (grid[r][c] == '1') {
                ++islands;
                dfs(grid, r, c);
            }

    return islands;
}

void Solution::dfs(vector<vector<char>>& grid, int r, int c) {
    grid[r][c] = '0';
    if (0 <= r - 1 && grid[r - 1][c] == '1')
        dfs(grid, r - 1, c);
    if (r + 1 < rows && grid[r + 1][c] == '1')
        dfs(grid, r + 1, c);
    if (0 <= c - 1 && grid[r][c - 1] == '1')
        dfs(grid, r, c - 1);
    if (c + 1 < cols && grid[r][c + 1] == '1')
        dfs(grid, r, c + 1);
}
