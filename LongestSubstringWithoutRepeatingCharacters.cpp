// Time: O(N)
// Space: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string);
};

int Solution::lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_index;
    int longest{};
    int l{};
    
    for (int r{0}; r < s.length(); r++) {
        if (char_index.contains(s[r]) && char_index[s[r]] >= l) {
            l = char_index[s[r]] + 1;
        } else {
            longest = max(longest, r - l + 1);
        }
        char_index[s[r]] = r;
    }

    return longest;
}
