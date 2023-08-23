// Time: O(N)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>&);
};

int Solution::maxProduct(vector<int>& nums) {
    int global_max_product = *max_element(nums.begin(), nums.end());
    int max_product = 1;
    int min_product = 1;
    int tmp_product = 1;

    for (auto& num : nums) {
        if (num == 0) {
            max_product = 1;
            min_product = 1;
        }
        tmp_product = max_product;
        max_product = max({ num, max_product * num, min_product * num });
        min_product = min({ num, min_product * num, tmp_product * num });
        global_max_product = max(global_max_product, max_product);
    }

    return global_max_product;
}
