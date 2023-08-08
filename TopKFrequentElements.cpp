class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> frequency;
        
        for (int& num : nums)
            frequency[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& k_v : frequency)
            buckets[k_v.second].push_back(k_v.first);

        vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; i--)
            for (int num : buckets[i])
            {
                res.push_back(num);
                --k;
                if (k == 0)
                    return res;
            }

        return res;
    }
};