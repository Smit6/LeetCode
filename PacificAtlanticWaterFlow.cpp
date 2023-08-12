// Time: O(M.N) - DFS function runs only once for each cell
// Space : O(M.N) - For each cell in pacific and atlantic ocean

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
private:
    int rows, cols;

    void dfs(vector<vector<int>>&, set<vector<int>>&, int, int, int);
};

vector<vector<int>> Solution::pacificAtlantic(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights[0].size();

    set<vector<int>> pacific;
    set<vector<int>> atlantic;

    for (int r = 0; r < rows; r++) {
        dfs(heights, pacific, -1, r, 0);
        dfs(heights, atlantic, -1, r, cols - 1);
    }

    for (int c = 0; c < cols; c++) {
        dfs(heights, pacific, -1, 0, c);
        dfs(heights, atlantic, -1, rows - 1, c);
    }

    vector<vector<int>> result;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) {
            vector<int> rc({ r, c });
            if ((pacific.find(rc) != pacific.end()) && (atlantic.find(rc) != atlantic.end()))
                result.push_back(rc);
        }

    return result;
}


void Solution::dfs(vector<vector<int>>& heights, set<vector<int>>& ocean, int prev_height, int r, int c) {
    vector<int> rc({ r, c });
    if (prev_height > heights[r][c] || ocean.find(rc) != ocean.end())
        return;

    ocean.insert(rc);

    if (0 <= r - 1)
        dfs(heights, ocean, heights[r][c], r - 1, c);
    if (r + 1 < rows)
        dfs(heights, ocean, heights[r][c], r + 1, c);
    if (0 <= c - 1)
        dfs(heights, ocean, heights[r][c], r, c - 1);
    if (c + 1 < cols)
        dfs(heights, ocean, heights[r][c], r, c + 1);
}
