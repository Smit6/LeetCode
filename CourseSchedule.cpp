class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        for (auto& prerequisite : prerequisites)
            adj_list[prerequisite[0]].emplace_back(std::move(prerequisite[1]));
        
        for (int crs = 0; crs < numCourses; crs++)
            if (!dfs(crs))
                return false;
        
        return true;
    }
private:
    unordered_map<int, vector<int>> adj_list;
    set<int> cycle;
    set<int> visited;

    bool dfs(int crs)
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

        return true;
    }
};