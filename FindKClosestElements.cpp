// Time: O((logN) + K)
// Space: O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>&, int, int);
};

vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
        int mid = (left + ((right - left) / 2));
        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return {arr.begin() + left, arr.begin() + left + k};
}
