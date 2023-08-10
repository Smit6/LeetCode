// Time: O(N)
// Space: O(1)

class Solution
{
public:
    int climbStairs(int);
};

int Solution::climbStairs(int n)
{
    if (n < 4)
        return n;

    int prev = 2;
    int cur = 3;
    int tmp = 0;

    for (int i = 4; i <= n; i++)
    {
        tmp = cur;
        cur += prev;
        prev = tmp;
    }
    
    return cur;
}
