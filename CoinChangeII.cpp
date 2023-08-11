// Time: O(N.C) - C is the lenght of coin and N is amount
// Space : O(N)

class Solution {
public:
    int change(int, vector<int>&);
private:
    vector<int> dp;
};

int Solution::change(int amount, vector<int>& coins) {
    dp = vector<int>(amount + 1, 0);
    dp[0] = 1;

    for (auto coin : coins)
        for (int amt = 1; amt <= amount; amt++)
            if (amt - coin >= 0)
                dp[amt] += dp[amt - coin];

    return dp.back();
}