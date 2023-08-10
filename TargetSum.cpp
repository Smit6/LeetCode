// Time: O(T.N) where T refers to the sum of the nums array
// The Cache of size O(T.N) has been filled just once.
// Space : O(T.N)

class Solution
{
public:
    int findTargetSumWays(vector<int>&, int);

private:
    int nums_size;
    map<pair<int, int>, int> cache;

    int backtrack(vector<int>&, int, int, int);
};

int Solution::findTargetSumWays(vector<int>& nums, int target)
{
    nums_size = nums.size();
    return backtrack(nums, 0, 0, target);
}

int Solution::backtrack(vector<int>& nums, int index, int cur_sum, int target)
{
    pair<int, int> index_sum(index, cur_sum);
    if (cache.find(index_sum) != cache.end())
        return cache[index_sum];

    if (index == nums_size - 1)
        return cur_sum + nums[index] == target;

    int res = backtrack(nums, index + 1, cur_sum + nums[index], target);
    res += backtrack(nums, index + 1, cur_sum - nums[index], target);
    cache[index_sum] = res;

    return res;
}
