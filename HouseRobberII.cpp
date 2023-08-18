// Time: O(N)
// Space: O(1)

class Solution {
public:
    int rob(vector<int>&);
private:
    int robbery(vector<int>&, int, int);
};

int Solution::robbery(vector<int>& nums, int l, int r) {
    int prev1 = 0;
    int prev2 = 0;
    int tmp = 0;

    for (int i = l; i <= r; i++) {
        tmp = prev1;
        prev1 = max(prev1, prev2 + nums[i]);
        prev2 = tmp;
    }

    return prev1;
}

int Solution::rob(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 1)
        return nums[0];
    return max(robbery(nums, 0, nums_size - 2), robbery(nums, 1, nums_size - 1));
}
