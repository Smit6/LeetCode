class Solution {
public:
    vector<vector<int>> permute(vector<int>&);
private:
    vector<int> cur;
    vector<vector<int>> result;

    void helper(vector<int>&);
};

vector<vector<int>> Solution::permute(vector<int>& nums) {
    helper(nums);
    return result;
}

void Solution::helper(vector<int>& nums) {
    if (cur.size() == nums.size()) {
        result.push_back(cur);
        return;
    }

    for (int num : nums)
        if (find(cur.begin(), cur.end(), num) == cur.end()) {
            cur.push_back(num);
            helper(nums);
            cur.pop_back();
        }
}
