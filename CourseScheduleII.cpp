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
            return set<int>();

    return res;
}

bool Solution::dfs(int crs)
{
    
}

