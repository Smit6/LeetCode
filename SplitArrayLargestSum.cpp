class Solution
{
public:
    int splitArray(vector<int>&, int);
    bool can_split(vector<int>&, int, int);
};

int Solution::splitArray(vector<int>& nums, int k)
{
    // Get possible range for binary search

    // Min sum is max element of array Thus l is set to max element
    int left = *max_element(nums.begin(), nums.end());
    // Max sum is accounts for largest sum and largest array
    int right = std::accumulate(nums.begin(), nums.end(), 0);

    int result = right;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + ((right - left) / 2));
        if (can_split(nums, mid, k))
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return result;
}

bool Solution::can_split(vector<int>& nums, int largest, int k)
{
    int sub_array = 0;
    int cur_sum = 0;
    for (auto& n : nums)
    {
        cur_sum += n;
        if (cur_sum > largest)
        {
            ++sub_array;
            cur_sum = n;
        }
    }
    return sub_array + 1 <= k;
}