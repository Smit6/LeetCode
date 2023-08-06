class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (!isalpha(s[left]) && !isdigit(s[left]))
            {
                ++left;
                continue;
            }
            if (!isalpha(s[right]) && !isdigit(s[right]))
            {
                --right;
                continue;
            }

            if (isalpha(s[left]))
                s[left] = tolower(s[left]);
            if (isalpha(s[right]))
                s[right] = tolower(s[right]);

            if (s[left] != s[right])
                return false;

            ++left, --right;
        }

        return true;
    }
};