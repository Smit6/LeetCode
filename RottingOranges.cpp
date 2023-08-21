// Time: O(R*C)
// Space: O(R*C)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid);
};

int Solution::orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    deque<pair<int, int>> q;
    int fresh = 0;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1)
                fresh++;
            else if (grid[r][c] == 2)
                q.push_back({r, c});
        }
    
    int minutes = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        if (!fresh)
            return minutes;

        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            auto [r, c] = q.front();
            q.pop_front();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (0 <= nr && nr < rows && 0 <= nc && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push_back({nr, nc});
                    fresh--;
                }
            }
        }

        minutes++;
    }

    return fresh ? -1 : minutes;
}
