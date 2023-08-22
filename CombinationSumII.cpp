// Time: O(2^N)
// Space: O(N)

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>&, int);
private:
    vector<vector<int>> result;
    vector<int> combination;
    void backtrack(vector<int>&, int, int);
};

void Solution::backtrack(vector<int>& candidates, int target, int i) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    if (target < 0 || i == candidates.size())
        return;
    
    int prev = -1;
    for (int j = i; j < candidates.size(); j++) {
        if (prev == candidates[j])
            continue;
        combination.push_back(candidates[j]);
        backtrack(candidates, target - candidates[j], j + 1);
        combination.pop_back();
        prev = candidates[j];
    }
}

vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0);
    return result;
}
