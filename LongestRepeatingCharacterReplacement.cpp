class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int longest = 0;
        int s_length = s.length();
        int max_element_count = 0;
        unordered_map<char, int> char_counter;

        for (int right = 0; right < s_length; right++)
        {
            char_counter[s[right]] += 1;
            max_element_count = max(max_element_count, char_counter[s[right]]);
            while (right - left + 1 - max_element_count > k)
                --char_counter[s[left]], ++left;
            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};
