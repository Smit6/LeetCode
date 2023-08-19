// Time: O(N * (4^N))
// Space: O(N)

class Solution {
public:
    vector<string> letterCombinations(string);
private:
    unordered_map<char, string> digit_chars;
    vector<string> result;

    void backtrack(int, string, const string&);
};

void Solution::backtrack(int index, string cur_s, const string& digits) {
    if (index == digits.length()) {
        result.push_back(cur_s);
        return;
    }

    for (auto& c : digit_chars[digits[index]])
        backtrack(index + 1, cur_s + c, digits);
}

vector<string> Solution::letterCombinations(string digits) {
    digit_chars = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    if (digits.length())
        backtrack(0, "", digits);
    return result;
}
