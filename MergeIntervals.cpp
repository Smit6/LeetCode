class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0], cur;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            cur = intervals[i + 1];
            if (prev[1] < cur[0])
            {
                res.push_back(prev);
                prev = cur;
            }
            else
            {
                prev[0] = min(prev[0], cur[0]);
                prev[1] = max(prev[1], cur[1]);
            }
        }
        res.push_back(prev);
        return res;
    }
};