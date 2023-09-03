// Time: O(2^N)
// Space: O(N)

class Solution {
public:
    string findDifferentBinaryString(vector<string>&);
private:
    unordered_set<string> set_nums;
    string backtrack(vector<string>&, string, int);
};


string Solution::backtrack(vector<string>& nums, string s, int i) {
    if (i == nums[0].size()) {
        if (!set_nums.contains(s))
            return s;
        else
            return "";
    }
    
    string s_0 = backtrack(nums, s + "0", i + 1);
    if (s_0 != "")
        return s_0;
    string s_1 = backtrack(nums, s + "1", i + 1);
    return s_1;
}


string Solution::findDifferentBinaryString(vector<string>& nums) {
    if (!nums.size())
        return "";

    set_nums.insert(nums.begin(), nums.end());

    return backtrack(nums, "", 0);
}
