// Time: O(R*C)
// Space: O(R*C)

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid);
private:
    int rows, cols;
    int dfs(vector<vector<int>>& grid, int r, int c);
};

int Solution::dfs(vector<vector<int>>& grid, int r, int c) {
    grid[r][c] = 0;
    int area = 1;
    if (0 <= r - 1 && grid[r - 1][c])
        area += dfs(grid, r - 1, c);
    if (r + 1 < rows && grid[r + 1][c])
        area += dfs(grid, r + 1, c);
    if (0 <= c - 1 && grid[r][c - 1])
        area += dfs(grid, r, c - 1);
    if (c + 1 < cols && grid[r][c + 1])
        area += dfs(grid, r, c + 1);
    return area;
}

int Solution::maxAreaOfIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int max_area = 0;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (grid[r][c])
                max_area = max(dfs(grid, r, c), max_area);
    
    return max_area;
}
