class Solution {
public:
    int maxProfit(vector<int>&);
};

int Solution::maxProfit(vector<int>& prices) {
    int profit{};
    int cost{numeric_limits<int>::max()};

    for (auto& price : prices) {
        cost = min(price, cost);
        profit = max(profit, price - cost);
    }

    return profit;
}
