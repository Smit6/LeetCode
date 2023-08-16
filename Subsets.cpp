// Time: O(N*(2^N))
// Space : O(N)


class Solution {
public:
    vector<vector<int>> subsets(vector<int>&);
private:
    vector<vector<int>> result;
    vector<int> subset;

    void backtrack(const vector<int>&, int);
};

void Solution::backtrack(const vector<int>& nums, int i) {
    if (i == nums.size()) {
        result.push_back(subset);
        return;
    }

    subset.push_back(nums[i]);
    backtrack(nums, i + 1);
    subset.pop_back();
    backtrack(nums, i + 1);
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
    backtrack(nums, 0);
    return result;
}
