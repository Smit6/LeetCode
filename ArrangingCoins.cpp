// Time: O(Log N)
// Space: O(1)

class Solution {
public:
    int arrangeCoins(int);
};

int Solution::arrangeCoins(int n) {
    int left = 1;
    int right = n;
    int mid = 0;
    int coins = 0;

    while (left <= right) {
        mid = (left + ((right - left) / 2));
        coins = (mid * (mid + 1)) / 2;
        if (coins > n)
            right = mid - 1;
        else if (coins < n)
            left = mid + 1;
        else
            return mid;
    }
    return left - 1;
}
