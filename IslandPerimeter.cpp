// Time: O(R*C)
// Space: O(1)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>&);
};

int Solution::islandPerimeter(vector<vector<int>>& grid) {
    const int ROWS = grid.size();
    const int COLS = grid[0].size();
    unsigned int perimeter = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (grid[r][c]) {
                // UP
                if (0 > r - 1 || !grid[r - 1][c]) perimeter++;
                // DOWN
                if (r + 1 >= ROWS || !grid[r + 1][c]) perimeter++;
                // LEFT
                if (0 > c - 1 || !grid[r][c - 1]) perimeter++;
                // RIGHT
                if (c + 1 >= COLS || !grid[r][c + 1]) perimeter++;
            }

    return perimeter;
}
