class Solution
{
public:
    int countSubstrings(string s)
    {
        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // ODD
            result += countPalindrome(s, i, i);
            // EVEN
            result += countPalindrome(s, i, i + 1);
        }

        return result;
    }
private:
    int countPalindrome(string& s, int l, int r)
    {
        int count = 0;

        while (0 <= l && r < s.length() && s[l] == s[r])
            ++count, --l, ++r;

        return count;
    }
};
