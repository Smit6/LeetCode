// Time: O(2^t), O(number of candidates^max depth)
// Space: O(N)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>&, int);
private:
    vector<int> combination;
    vector<vector<int>> combinations;

    void backtrack(vector<int>&, int, int, int);
};

void Solution::backtrack(vector<int>& candidates, int target, int cur_sum, int i) {
    if (cur_sum == target) {
        combinations.push_back(combination);
        return;
    }
    if (i == candidates.size() || target < cur_sum)
        return;

    combination.push_back(candidates[i]);
    backtrack(candidates, target, cur_sum + candidates[i], i);
    combination.pop_back();
    backtrack(candidates, target, cur_sum, i + 1);
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target) {
    backtrack(candidates, target, 0, 0);
    return combinations;
}
