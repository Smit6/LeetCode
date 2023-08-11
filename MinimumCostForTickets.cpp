// Time: O(N) - N is the number of unique days to travel
// Space : O(N)

class Solution {
public:
    int mincostTickets(vector<int>&, vector<int>&);
private:
    unordered_map<int, int> day_cost;
    struct travel_cost_day {
        int cost;
        int days;
    };
    vector<int> pass_days;
    vector<travel_cost_day> passes;
    int backtrack(vector<int>&, vector<int>&, int);
};

int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
    pass_days = vector<int>({ 1, 7, 30 });
    for (int i = 0; i < costs.size(); i++) {
        travel_cost_day tcd = {
            costs[i],
            pass_days[i]
        };
        passes.push_back(tcd);
    }
    return backtrack(days, costs, 0);
}

int Solution::backtrack(vector<int>& days, vector<int>& costs, int i) {
    if (i == days.size())
        return 0;

    if (day_cost.find(i) != day_cost.end())
        return day_cost[i];

    day_cost[i] = INT_MAX;
    int j = 0;
    for (auto& pass_cost_days : passes) {
        j = i;
        while (j < days.size() && days[i] + pass_cost_days.days > days[j])
            j++;
        day_cost[i] = min(day_cost[i], pass_cost_days.cost + backtrack(days, costs, j));
    }

    return day_cost[i];
}
