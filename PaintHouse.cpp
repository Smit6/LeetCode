// Time: O(N)
// Space: O(1)

class Solution {
public:
    int minCost(vector<vector<int>>&);
};

int Solution::minCost(vector<vector<int>>& costs) {
    vector<int> dp(3, 0);
    int dp0, dp1, dp2;

    for (auto& cost: costs) {
        dp0 = cost[0] + min(dp[1], dp[2]);
        dp1 = cost[1] + min(dp[0], dp[2]);
        dp2 = cost[2] + min(dp[0], dp[1]);

        dp[0] = dp0;
        dp[1] = dp1;
        dp[2] = dp2;
    }

    return *min_element(dp.begin(), dp.end());
}
