// Time: O(N^2)
// Space: O(N)

class Solution {
public:
    int numTrees(int);
};

int Solution::numTrees(int n) {
    vector<int> dp(n + 1, 1);
    int total = 0;
    int left = 0;
    int right = 0;

    // 0 node can make 1 Tree
    // 1 node can make 1 Tree
    for (int nodes = 2; nodes <= n; nodes++) {
        total = 0;
        for (int root = 1; root <= nodes; root++) {
            left = root - 1;
            right = nodes - root;
            total += dp[left] * dp[right];
        }
        dp[nodes] = total;
    }
    return dp.back();
}
