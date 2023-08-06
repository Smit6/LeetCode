class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> ch_map;
        int s_size = s.length();
        int cur_substr_index = 0;
        int max_length = 0;

        //a b c a b c b b
        for (int i = 0; i < s_size; i++)
        {
            if (ch_map.find(s[i]) != ch_map.end() && ch_map[s[i]] >= cur_substr_index)
                cur_substr_index = ch_map[s[i]] + 1;
            else
                max_length = max(max_length, i - cur_substr_index + 1);
            ch_map[s[i]] = i;
        }

        return max_length;
    }
};