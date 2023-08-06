class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals)
    {
        if (!intervals.size()) return true;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        vector<int> cur;
        for (auto it = ++intervals.begin(); it != intervals.end(); it++)
        {
            cur = *it;
            if (prev[1] > cur[0])
                return false;
            prev = cur;
        }
        return true;
    }
};