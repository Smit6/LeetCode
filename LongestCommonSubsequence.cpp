class Solution {
public:
    int longestCommonSubsequence(string, string);
};

int Solution::longestCommonSubsequence(string text1, string text2) {
    int rows = text2.length();
    int cols = text1.length();

    vector<vector<int>> dp(rows + 1, vector<int> (cols + 1, 0));

    for (int r = 1; r <= rows; r++)
        for (int c = 1; c <= cols; c++)
            if (text1[c - 1] == text2[r - 1])
                dp[r][c] = dp[r - 1][c - 1] + 1;
            else
                dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
    
    return dp[rows][cols];
}
