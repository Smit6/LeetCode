// Time: O(N * (log N)), Where N is number of cells in grid, Log N time to perform heap operation
// Space: O(N)

class Solution {
public:
    int swimInWater(vector<vector<int>>&);
};

int Solution::swimInWater(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.size();

    set<pair<int, int>> visited;
    visited.insert(make_pair(0, 0));
    vector<pair<int, int>> directions({ make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) });

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push(vector<int>({ grid[0][0], 0, 0 }));

    int t = 0;
    int nei_r, nei_c;

    while (pq.size()) {
        auto t_r_c = pq.top();
        pq.pop();

        t = t_r_c[0];

        if (t_r_c[1] == rows - 1 && t_r_c[2] == cols - 1)
            return t_r_c[0];
        
        for (auto& direction : directions) {
            nei_r = t_r_c[1] + direction.first;
            nei_c = t_r_c[2] + direction.second;
            auto rc = make_pair(nei_r, nei_c);
            if (0 <= nei_r && nei_r < rows && 0 <= nei_c && nei_c < cols && visited.find(rc) == visited.end()) {
                visited.insert(rc);
                pq.push(vector<int>({ max(t_r_c[0], grid[nei_r][nei_c]), nei_r, nei_c }));
            }
        }
    }

    return t;
}
