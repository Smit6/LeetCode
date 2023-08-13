// Time: O(N ^ 2)
// Space : O(1)

class Solution {
public:
    string longestPalindrome(string);
};

string Solution::longestPalindrome(string s) {
    int s_length = s.length();
    int left = 0;
    int right = 0;
    int longest_length = 0;
    int current_length = 0;
    pair<int, int> longest_palindrome_index(0, 0);

    for (int i = 0; i < s_length; i++) {
        // ODD
        left = i, right = i;
        while (0 <= left && right < s_length && s[left] == s[right]) {
            current_length = right - left + 1;
            if (current_length > longest_length) {
                longest_length = current_length;
                longest_palindrome_index.first = left;
                longest_palindrome_index.second = right;
            }
            --left, ++right;
        }

        // EVEN
        left = i, right = i + 1;
        while (0 <= left && right < s_length && s[left] == s[right]) {
            current_length = right - left + 1;
            if (current_length > longest_length) {
                longest_length = current_length;
                longest_palindrome_index.first = left;
                longest_palindrome_index.second = right;
            }
            --left, ++right;
        }
    }

    return s.substr(longest_palindrome_index.first, longest_palindrome_index.second - longest_palindrome_index.first + 1);
}
