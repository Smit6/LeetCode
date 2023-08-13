// Time: O(N ^ 2)
// Space : O(N)

class Solution {
public:
    int minimumTotal(vector<vector<int>>&);
};

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp(triangle.back().size() + 1, 0);

    for (int i = triangle.size() - 1; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
    
    return dp[0];
}
