// Time: O(N), where N is the number of cells in rooms
// Space: O(N)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>&);
};

// -1 : wall
// 0 : gate
// INF : empty

void Solution::wallsAndGates(vector<vector<int>>& rooms) {
    int rows = rooms.size();
    int cols = rooms[0].size();
    deque<pair<int, int>> q;
    set<pair<int, int>> visited;
    
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (rooms[r][c] == 0) {
                auto rc = make_pair(r, c);
                q.push_back(rc);
                visited.insert(rc);
            }
    
    vector<pair<int, int>> directions({ make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0) });

    int distance = 0;
    int q_size = 0;
    int nei_r = 0, nei_c = 0;
    while (q.size()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            auto rc = q.front();
            q.pop_front();
            rooms[rc.first][rc.second] = distance;

            for (auto& direction: directions) {
                nei_r = rc.first + direction.first;
                nei_c = rc.second + direction.second;
                auto nei_rc = make_pair(nei_r, nei_c);
                if (0 <= nei_r && nei_r < rows && 0 <= nei_c && nei_c < cols && visited.find(nei_rc) == visited.end() && rooms[nei_r][nei_c] != -1) {
                    visited.insert(nei_rc);
                    q.push_back(nei_rc);
                }
            }
        }
        distance++;
    }
}
