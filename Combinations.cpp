// Time: O(N^K)
// Space: O(K)

class Solution {
public:
    vector<vector<int>> combine(int, int);
private:
    vector<int> combination;
    vector<vector<int>> combinations;

    void backtrack(int, int, int, int);
};

void Solution::backtrack(int i, int j, int n, int k) {
    if (i == k) {
        combinations.push_back(combination);
        return;
    }

    if (j > n)
        return;
    
    combination.push_back(j);
    backtrack(i + 1, j + 1, n, k);
    combination.pop_back();
    backtrack(i, j + 1, n, k);
}

vector<vector<int>> Solution::combine(int n, int k) {
    backtrack(0, 1, n, k);
    return combinations;
}