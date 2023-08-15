// Time: O(N + E)
// Space: O(N + E)

class Solution
{
private:
    set<int> visited;
    unordered_map<int, vector<int>> adj_list;

    bool dfs(int, int);
public:
    bool validTree(int, vector<vector<int>>&);
};

bool Solution::dfs(int v, int prev_v)
{
    if (visited.find(v) != visited.end()) return false;
    visited.insert(v);

    for (auto adj_v : adj_list[v])
        if (adj_v != prev_v && !dfs(adj_v, v)) return false;

    return true;
}

bool Solution::validTree(int n, vector<vector<int>>& edges)
{
    for (auto& edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }
    return dfs(0, -1) && n == visited.size();
}
