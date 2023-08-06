class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> s_count;
        unordered_map<char, int> t_count;

        for (int i = 0; i < s.length(); i++)
            ++s_count[s[i]], ++t_count[t[i]];

        for (const auto& k_v : s_count)
            if (k_v.second != (t_count.find(k_v.first) != t_count.end() ? t_count[k_v.first] : 0))
                return false;

        return true;
    }
};