// Time: O(R*C)
// Space: O(R*C)

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>&);
private:
    int rows{0};
    int cols{0};
    map<pair<int, int>, int> cache;
    int dfs(const vector<vector<int>>&, int, int, int);
};

int Solution::dfs(const vector<vector<int>>& matrix, int r, int c, int prev) {
    if (prev >= matrix[r][c])
        return 0;
    auto rc = make_pair(r, c);
    if (cache.contains(rc))
        return cache[rc];
    
    int rc_longest{0};
    if (0 <= r - 1)
        rc_longest = max(rc_longest, dfs(matrix, r - 1, c, matrix[r][c]));
    if (r + 1 < rows)
        rc_longest = max(rc_longest, dfs(matrix, r + 1, c, matrix[r][c]));
    if (0 <= c - 1)
        rc_longest = max(rc_longest, dfs(matrix, r, c - 1, matrix[r][c]));
    if (c + 1 < cols)
        rc_longest = max(rc_longest, dfs(matrix, r, c + 1, matrix[r][c]));
    
    cache[rc] = rc_longest + 1;
    return cache[rc];
}

int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
    int longest{0};

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            longest = max(longest, dfs(matrix, r, c, -1));

    return longest;
}
