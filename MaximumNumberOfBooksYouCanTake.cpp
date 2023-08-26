// Time: O(N)
// Space: O(N)

class Solution {
public:
    long long maximumBooks(vector<int>&);
};

long long Solution::maximumBooks(vector<int>& books) {
    long long maximum{};
    long long cur{};
    stack<int> ms;
    vector<long long> dp(books.size());

    auto sum = [](long long n) {
        return n <= 0 ? 0 : (n * (n + 1)) / 2;
    };

    for (int i = 0; i < books.size(); i++) {
        while (!ms.empty() && books[ms.top()] >= books[i] - (i - ms.top()))
            ms.pop();
        
        if (ms.empty())
            dp[i] = sum(books[i]) - sum(books[i] - i - 1);
        else
            dp[i] = dp[ms.top()] + sum(books[i]) - sum(books[i] - (i - ms.top()));
        
        maximum = max(maximum, dp[i]);
        ms.push(i);
    }

    return maximum;
}
