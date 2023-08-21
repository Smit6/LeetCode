// Time: O(E * log(E/V)), E = number of flights, V = number of airports
// Space: O(E + V)

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>&);
private:
    vector<string> result;
    unordered_map<string, vector<string>> adj_list;
    bool dfs(string, vector<vector<string>>&);
};

bool Solution::dfs(string src, vector<vector<string>>& tickets) {
    if (tickets.size() + 1 == result.size())
        return true;
    
    if (adj_list.find(src) == adj_list.end())
        return false;
    
    auto list = adj_list[src];
    for (int i = 0; i < list.size(); i++) {
        adj_list[src].erase(adj_list[src].begin() + i);
        result.push_back(list[i]);
        if (dfs(list[i], tickets))
            return true;
        adj_list[src].insert(adj_list[src].begin() + i, list[i]);
        result.pop_back();
    }

    return false;
}

vector<string> Solution::findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end());

    for (auto& ticket : tickets) {
        adj_list[ticket[0]].push_back(ticket[1]);
    }

    result.push_back("JFK");

    dfs("JFK", tickets);
    return result;
}
