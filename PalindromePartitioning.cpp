// Time: O(N * (2 ^ N))
// Space : O(N)

class Solution {
public:
    vector<vector<string>> partition(string);
private:
    vector<string> palindromic_partitions;
    vector<vector<string>> result;

    bool ipalindromic_partitions(const string&, int, int);
    void backtrack(const string&, int);
};

bool Solution::ipalindromic_partitions(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    
    return true;
}

void Solution::backtrack(const string& s, int i) {
    if (i == s.length()) {
        result.push_back(palindromic_partitions);
        return;
    }

    for (int j = i; j < s.length(); j++)
        if (ipalindromic_partitions(s, i, j)) {
            palindromic_partitions.push_back(s.substr(i, j - i + 1));
            backtrack(s, j + 1);
            palindromic_partitions.pop_back();
        }

}

vector<vector<string>> Solution::partition(string s) {
    backtrack(s, 0);
    return result;
}
