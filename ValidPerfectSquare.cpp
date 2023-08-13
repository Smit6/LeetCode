// Time: O(log N)
// Space: O(1)

class Solution {
public:
    bool isPerfectSquare(int);
};

bool Solution::isPerfectSquare(int num) {
    if (num < 0)
        return false;
    if (num == 0 || num == 1)
        return true;

    int left = 2, right = num / 2;
    int64_t mid = 0;
    int64_t mid_square = mid * mid;

    while (left <= right) {
        mid = left + ((right - left) / 2);
        mid_square = mid * mid;

        if (mid_square < num)
            left = mid + 1;
        else if (mid_square > num)
            right = mid - 1;
        else
            return true;
    }
    return false;
}
