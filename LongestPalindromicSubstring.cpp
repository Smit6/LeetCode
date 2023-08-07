class Solution
{
public:
    string longestPalindrome(string s)
    {
        int s_length = s.length();
        int left = 0, right = 0;
        int longest_length = 0, current_length = 0;
        pair<int, int> longest_palindrome_idx(0, 0);

        for (int i = 0; i < s_length; i++)
        {
            // ODD
            left = i, right = i;
            current_length = 0;
            while (0 <= left && right < s_length && s[left] == s[right])
            {
                current_length = right - left + 1;
                if (current_length > longest_length) {
                    longest_length = current_length;
                    longest_palindrome_idx.first = left;
                    longest_palindrome_idx.second = right;
                }
                --left, ++right;
            }

            // EVEN
            left = i, right = i + 1;
            current_length = 0;
            while (0 <= left && right < s_length && s[left] == s[right])
            {
                current_length = right - left + 1;
                if (current_length > longest_length) {
                    longest_length = current_length;
                    longest_palindrome_idx.first = left;
                    longest_palindrome_idx.second = right;
                }
                --left, ++right;
            }
        }

        cout << longest_palindrome_idx.first << ", " << longest_palindrome_idx.second;

        return s.substr(longest_palindrome_idx.first, longest_palindrome_idx.second - longest_palindrome_idx.first + 1);
    }
};
