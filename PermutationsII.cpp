// Time: O(N!)
// Space : O(N) - Space for permutation

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>&);
private:
    vector<vector<int>> result;
    vector<int> permutation;
    unordered_map<int, int> num_counter;

    void backtrack(vector<int>&);
};

vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    for (auto num : nums)
        num_counter[num]++;
    backtrack(nums);
    return result;
}

void Solution::backtrack(vector<int>& nums) {
    if (nums.size() == permutation.size()) {
        result.push_back(permutation);
        return;
    }

    for (auto& k_v : num_counter)
        if (num_counter[k_v.first] > 0) {
            num_counter[k_v.first] -= 1;
            permutation.push_back(k_v.first);
            backtrack(nums);
            num_counter[k_v.first]++;
            permutation.pop_back();
        }
}
