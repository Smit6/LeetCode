// Time: O(N)
// Space: O(1)

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (auto& num : data)
            ones += num;
        
        int zeros = data.size() - ones;
        int l = 0;
        int r = 0;
        int max_ones = 0;
        int cur_ones = 0;

        while (r < data.size()) {
            cur_ones += data[r];
            if (r - l + 1 < ones)
                cur_ones -= data[l++];
            max_ones = max(max_ones, cur_ones);
            r++;
        }

        return ones - max_ones;
    }
};
