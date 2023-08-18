// Time: O(N ^ 2.log(N)) - worst case N ^ 2 edges, each push and pop takes log N
// Space: O(N ^ 2) - worst case N ^ 2 edges

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>&);
private:
    set<int> visited;
    unordered_map<int, vector<pair<int, int>>> adj_list;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Priority Q
};

int Solution::minCostConnectPoints(vector<vector<int>>& points) {
    int num_points = points.size();
    int x1, x2, y1, y2;
    int dist = 0;
    for (int i = 0; i < num_points; i++) {
        x1 = points[i][0];
        y1 = points[i][1];
        for (int j = i + 1; j < num_points; j++) {
            x2 = points[j][0];
            y2 = points[j][1];
            dist = abs(x1 - x2) + abs(y1 - y2);
            adj_list[i].push_back(make_pair(dist, j));
            adj_list[j].push_back(make_pair(dist, i));
        }
    }

    pq.push(make_pair(0, 0)); // cost, point index in points
    int min_cost = 0;

    while (!pq.empty()) {
        pair<int, int> cost_pi = pq.top();
        pq.pop();
        if (visited.find(cost_pi.second) == visited.end()) {
            min_cost += cost_pi.first;
            visited.insert(cost_pi.second);
            for (auto& adj_pi : adj_list[cost_pi.second])
                pq.push(make_pair(adj_pi.first, adj_pi.second));
        }
    }

    return min_cost;
}
