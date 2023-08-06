class Solution
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        vector<int> starts_at, ends_at;
        for (auto& interval : intervals)
        {
            starts_at.push_back(interval[0]);
            ends_at.push_back(interval[1]);
        }
        
        sort(starts_at.begin(), starts_at.end());
        sort(ends_at.begin(), ends_at.end());

        int starts_i = 0, ends_i = 0;
        int cur_rooms = 0, max_rooms = 0;
        int intervals_size = intervals.size();

        // starts_at = [0, 5, 15]
        // ends_at = [10, 20, 30]

        while (starts_i < intervals_size)
        {
            if (starts_at[starts_i] < ends_at[ends_i])
            {
                ++starts_i;
                ++cur_rooms;
                max_rooms = max(max_rooms, cur_rooms);
            }
            else
            {
                --cur_rooms;
                ++ends_i;
            }
        }

        return max_rooms;
    }
};