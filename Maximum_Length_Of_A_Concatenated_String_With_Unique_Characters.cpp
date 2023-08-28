// Time: O(2^N)
// Space: O(N)

class Solution {
public:
    int maxLength(vector<string>&);
private:
    unordered_set<char> char_set;
    bool overlap(const string&);
    int backtrack(vector<string>&, int);
};

bool Solution::overlap(const string& s) {
    set<char> Counter(char_set.begin(), char_set.end());

    for (auto c : s) {
        if (Counter.contains(c))
            return true;
        else
            Counter.insert(c);
    }
    
    return false;
}

int Solution::backtrack(vector<string>& arr, int i) {
    if (i == arr.size())
        return char_set.size();
    
    int res = 0;
    if (!overlap(arr[i])) {
        char_set.insert(arr[i].begin(), arr[i].end());
        res = backtrack(arr, i + 1);
        for (auto c : arr[i])
            char_set.erase(c);
    }

    return max(res, backtrack(arr, i + 1));
    
}

int Solution::maxLength(vector<string>& arr) {
    return backtrack(arr, 0);
}
