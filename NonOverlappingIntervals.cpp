class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int non_overlapping = 0;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        vector<int> cur;
        for (auto it = ++intervals.begin(); it != intervals.end(); it++)
        {
            cur = *it;
            if (prev[1] > cur[0])
            {
                cur = { prev[0], min(prev[1], cur[1]) };
                non_overlapping++;
            }
            
            prev = cur;
        }
        return non_overlapping;
    }
};