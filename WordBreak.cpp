class Solution {
public:
    bool wordBreak(string, vector<string>&);
private:
    set<string> word_set;
    vector<int> dp;
};

bool Solution::wordBreak(string s, vector<string>& wordDict) {
    int s_length = s.length();
    word_set = set<string>(wordDict.begin(), wordDict.end());
    dp = vector<int>(s_length + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= s.length(); i++)
        for (int j = 0; j < i; j++)
            if (dp[j] && (word_set.find(s.substr(j, i - j)) != word_set.end())) {
                dp[i] = true;
                break;
            }

    return dp[s_length];
}
