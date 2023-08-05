class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int intervals_size = intervals.size();
        for (int i = 0; i < intervals_size; i++) {
            if (newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                for (i; i < intervals_size; i++)
                    res.push_back(intervals[i]);
                return res;
            }
            else if (intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};