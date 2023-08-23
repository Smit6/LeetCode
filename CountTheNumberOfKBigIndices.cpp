// Time: O(N)
// Space: O(N)

class Solution {
public:
    int kBigIndices(vector<int>&, int);
};

int Solution::kBigIndices(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    bool left_big_i[n];
    bool right_big_i[n];
    priority_queue<int> pq_left;
    priority_queue<int> pq_right;

    for (int i = 0; i < k; i++) {
        pq_left.push(nums[i]);
        pq_right.push(nums[n - i - 1]);
    }

    for (int i = k; i <= n - k; i++) {
        left_big_i[i] = pq_left.top() < nums[i];
        pq_left.push(nums[i]);
        pq_left.pop();

        right_big_i[i] = pq_right.top() < nums[n - i - 1];
        pq_right.push(nums[n - i - 1]);
        pq_right.pop();
    }

    for (int i = k; i < n - k; i++)
        ans += int(left_big_i[i] && right_big_i[i]);
    
    return ans;
}
