// Time: O(M * N)
// Space: O(M * N)

class Solution {
public:
    bool isMatch(string, string);
};

bool Solution::isMatch(string s, string p) {
    int rows = s.size();
    int cols = p.size();

    vector<vector<bool>> cache(rows + 1, vector<bool>(cols + 1, false));
    cache[0][0] = true;

    // Deals with pattern like a* or a*b* or a*b*c*
    // where * means zero or more of the preceding element
    // and the preceding element is a single character
    for (int col = 2; col <= cols; col++)
        cache[0][col] = p[col - 1] == '*' && cache[0][col - 2];

    for (int row = 1; row <= rows; row++)
        for (int col = 1; col <= cols; col++)
            if (p[col - 1] == '.' || p[col - 1] == s[row - 1])
                cache[row][col] = cache[row - 1][col - 1];
            else if (p[col - 1] == '*') {
                cache[row][col] = cache[row][col - 2];
                if (p[col - 2] == '.' || p[col - 2] == s[row - 1])
                    cache[row][col] = cache[row][col] || cache[row - 1][col];
            }

    return cache[rows][cols];

}
