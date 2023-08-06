class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t == "")
            return "";

        unordered_map<char, int> window_char;
        unordered_map<char, int> t_char;
        for (auto& c : t)
            t_char[c]++;

        int have = 0;
        int need = t_char.size();

        pair<int, int> min_window(-1, -1);
        int min_length = INT_MAX;

        int left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            window_char[s[right]]++;
            if (window_char[s[right]] == t_char[s[right]])
                have++;

            while (have == need)
            {
                if (right - left + 1 < min_length)
                {
                    min_length = right - left + 1;
                    min_window.first = left;
                    min_window.second = right;
                }
                --window_char[s[left]];
                if (window_char[s[left]] < t_char[s[left]])
                    --have;
                ++left;
            }
        }

        return min_length == INT_MAX ? "" : s.substr(min_window.first, min_window.second - min_window.first + 1);
    }
};