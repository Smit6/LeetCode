// Time: O(2^N)
// Space: O(N)

class Solution {
public:
    bool splitString(string);
private:
    bool backtrack(const string&, int, unsigned long long);
};

bool Solution::backtrack(const string& s, int i, unsigned long long prev_val) {
    if (i == s.length())
        return true;
    unsigned long long val = 0;
    for (int j = i; j < s.length(); j++) {
        val = stoull(s.substr(i, j - i + 1));
        if (prev_val == val + 1 && backtrack(s, j + 1, val))
            return true;
    }
    return false;
}

bool Solution::splitString(string s) {
    unsigned long long val = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        val = stoull(s.substr(0, i + 1));
        if (backtrack(s, i + 1, val))
            return true;
    }

    return false;
}
