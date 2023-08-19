// Time: O((N + E) * K), N is number of cities, E is number fo flights, at most K stops
// Space: O(N)

class Solution {
public:
    int findCheapestPrice(int, vector<vector<int>>&, int, int, int);
};

// flights: from, to, price
// n: num of cities

int Solution::findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prices(n, numeric_limits<int>::max());
    prices[src] = 0;

    // At most k stops
    for (int i = 0; i <= k; i++) {
        vector<int> tmp_prices(prices);
        for (auto& s_d_p : flights)
            if (prices[s_d_p[0]] != numeric_limits<int>::max() && prices[s_d_p[0]] + s_d_p[2] < tmp_prices[s_d_p[1]])
                tmp_prices[s_d_p[1]] = prices[s_d_p[0]] + s_d_p[2];
        prices = tmp_prices;
    }

    return prices[dst] == numeric_limits<int>::max() ? -1 : prices[dst];
}
