class Solution {
public:
    int minimumOperations(vector<int>&);
};

int Solution::minimumOperations(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int num_merges = 0;
    long long left_value = 0;
    long long right_value = 0;

    while (l < r) {
        if (r == l + 1)
            return num_merges;
        
        left_value = nums[l];
        right_value = nums[r];

        while (left_value != right_value) {
            if (r == l + 1)
                return ++num_merges;
            
            if (left_value > right_value)
                right_value += nums[--r];
            else
                left_value += nums[++l];

            num_merges++;
        }
        l++;
        r--;
    }

    return num_merges;
}
