// Time: (M.N)
// Space: (M.N)

class Solution {
public:
    bool isInterleave(string, string, string);
private:
    bool backtrack(const string&, const string&, const string&, int, int);
    map<pair<char, char>, bool> cache;
};

bool Solution::isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())
        return false;
    return backtrack(s1, s2, s3, 0, 0);
}

bool Solution::backtrack(const string& s1, const string& s2, const string& s3, int i1, int i2) {
    if (i1 == s1.length() && i2 == s2.length())
        return true;

    pair<int, int> p12 = make_pair(i1, i2);

    if (cache.find(p12) != cache.end())
        return cache[p12];

    if (i1 < s1.size() && s1[i1] == s3[i1 + i2] && backtrack(s1, s2, s3, i1 + 1, i2))
        return true;
    if (i2 < s2.size() && s2[i2] == s3[i1 + i2] && backtrack(s1, s2, s3, i1, i2 + 1))
        return true;

    cache[p12] = false;
    return false;
}
