// Time: O(N)
// Space: O(N)

class Solution {
public:
    int coinChange(vector<int>&, int);
};

int Solution::coinChange(vector<int>& coins, int amount) {
    vector<int> cache(amount + 1, amount + 1);
    cache[0] = 0;
    
    for (int amt = 1; amt <= amount; amt++)
        for (auto& coin : coins)
            if (amt - coin >= 0)
                cache[amt] = min(cache[amt - coin] + 1, cache[amt]);
    
    return cache.back() == amount + 1 ? -1 : cache.back();
}
