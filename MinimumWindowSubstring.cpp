// Time: O(N), N is the sum of the lengths of s and t
// Space: O(N)

class Solution {
public:
    string minWindow(string, string);
};

string Solution::minWindow(string s, string t) {
    unordered_map<char, int> window_count;
    unordered_map<char, int> t_count;
    for (auto& ch_t : t)
        t_count[ch_t]++;
    
    int have{};
    int need = t_count.size();

    int min_len{numeric_limits<int>::max()};
    pair<int, int> min_window;

    int l{};
    for (int r{0}; r < s.length(); r++) {
        window_count[s[r]]++;
        if (window_count[s[r]] == t_count[s[r]])
            ++have;
        
        while (have == need) {
            if (r - l + 1 < min_len) {
                min_len = r - l + 1;
                min_window = make_pair(l, r);
            }
            --window_count[s[l]];
            if (window_count[s[l]] < t_count[s[l]])
                --have;
            ++l;
        }
    }

    return min_len == numeric_limits<int>::max() ? "" : s.substr(min_window.first, min_len);
}
