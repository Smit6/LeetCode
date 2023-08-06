class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<vector<int>, vector<string>> group_anagrams;

        for (const auto& s : strs)
        {
            vector<int> key(26, 0);
            for (const auto& c : s)
                ++key[c - 'a'];
            group_anagrams[key].push_back(s);
        }

        vector<vector<string>> group_anagrams_res;
        for (const auto& k_v : group_anagrams)
            group_anagrams_res.push_back(k_v.second);

        return group_anagrams_res;
    }
};