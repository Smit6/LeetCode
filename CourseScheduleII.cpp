// Time: O(N.3 ^ L) - L is the length of word and N is number of cells
// Space : O(L)

class Solution {
public:
    vector<int> findOrder(int, vector<vector<int>>&);

private:
    vector<int> res;
    set<int> visited;
    set<int> cycle;
    unordered_map<int, vector<int>> adj_list;

    bool dfs(int);
};

vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    for (auto& pre : prerequisites)
        adj_list[pre[0]].emplace_back(move(pre[1]));

    for (int crs = 0; crs < numCourses; crs++)
        if (!dfs(crs))
            return vector<int>();

    return res;
}

bool Solution::dfs(int crs)
{
    if (cycle.find(crs) != cycle.end())
        return false;
    if (visited.find(crs) != visited.end())
        return true;

    visited.insert(crs);
    cycle.insert(crs);

    for (auto& adj_crs : adj_list[crs])
        if (!dfs(adj_crs))
            return false;

    cycle.erase(crs);

    res.emplace_back(move(crs));
    return true;
}

