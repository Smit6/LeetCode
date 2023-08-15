// Time: O(N)
// Space: O(N)

class Solution {
public:
    int numDecodings(string);
private:
    int dfs(int, const string&);
    unordered_map<int, int> cache;
    set<char> second_chars;
};

int Solution::numDecodings(string s) {
    second_chars = { '0', '1', '2', '3', '4', '5', '6' };
    cache[s.length()] = 1;
    return dfs(0, s);
}

int Solution::dfs(int i, const string& s) {
    if (cache.find(i) != cache.end())
        return cache[i];

    if (s[i] == '0')
        return 0;

    int num_decodings = dfs(i + 1, s);
    if (i + 1 < s.length()
        && ((s[i] == '1' || (s[i] == '2' && second_chars.find(s[i + 1]) != second_chars.end()))))
        num_decodings += dfs(i + 2, s);
    cache[i] = num_decodings;
    return num_decodings;
}
