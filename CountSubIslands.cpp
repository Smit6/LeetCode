class Solution {
public:
    int countSubIslands(vector<vector<int>>&, vector<vector<int>>&);
private:
    int rows, cols;
    set<pair<int, int>> visited;
    int dfs(vector<vector<int>>&, vector<vector<int>>&, int, int);
};

int Solution::dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
    auto pc = make_pair(r, c);
    if (visited.find(pc) != visited.end())
        return 1;

    grid2[r][c] = 0;
    int ret = grid1[r][c] ? 1 : 0;

    if (0 <= r - 1 && grid2[r - 1][c])
        ret = dfs(grid1, grid2, r - 1, c) && ret ? 1 : 0;
    if (r + 1 < rows && grid2[r + 1][c])
        ret = dfs(grid1, grid2, r + 1, c) && ret ? 1 : 0;
    if (0 <= c - 1 && grid2[r][c - 1])
        ret = dfs(grid1, grid2, r, c - 1) && ret ? 1 : 0;
    if (c + 1 < cols && grid2[r][c + 1])
        ret = dfs(grid1, grid2, r, c + 1) && ret ? 1 : 0;

    return ret;
}

int Solution::countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    rows = grid1.size();
    cols = grid1[0].size();

    int islands = 0;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (grid2[r][c])
                islands += dfs(grid1, grid2, r, c);

    return islands;
}
