class Solution {
public:
    int lengthOfLIS(vector<int>&);
};

int Solution::lengthOfLIS(vector<int>& nums) {
    int nums_size = nums.size();
    vector<int> dp(nums.size(), 1);

    for (int i = nums_size; i >= 0; i--)
        for (int j = i; j < nums_size; j++)
            if (nums[i] < nums[j])
                dp[i] = max(dp[j] + 1, dp[i]);

    return *max_element(dp.begin(), dp.end());
}
