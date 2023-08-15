// Time: O(V + E)
// Space: O(V + E)

class Solution {
public:
    int minReorder(int, vector<vector<int>>&);
private:
    set<pair<int, int>> edges;
    set<int> visited;
    unordered_map<int, vector<int>> adj_list;
    deque<int> q;
};

int Solution::minReorder(int n, vector<vector<int>>& connections) {
    for (vector<int>& conn : connections) {
        adj_list[conn[0]].push_back(conn[1]);
        adj_list[conn[1]].push_back(conn[0]);
        edges.insert(make_pair(conn[0], conn[1]));
    }

    q.push_back(0);
    int res = 0;
    int u = 0;

    while (q.size()) {
        u = q.front();
        q.pop_front();
        visited.insert(u);

        for (int v : adj_list[u]) {
            if (visited.find(v) == visited.end()) {
                if (edges.find(make_pair(v, u)) == edges.end())
                    res++;
                q.push_back(v);
            }
        }
    }

    return res;
}
