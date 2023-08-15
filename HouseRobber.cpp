// Time: O(N)
// Space: O(1)

class Solution {
public:
    int rob(vector<int>&);
};

int Solution::rob(vector<int>& nums) {
    if (!nums.size())
        return 0;

    int prev1 = 0;
    int prev2 = 0;
    int tmp = 0;

    for (int& n : nums) {
        tmp = prev1;
        prev1 = max(prev1, prev2 + n);
        prev2 = tmp;
    }

    return prev1;
}
