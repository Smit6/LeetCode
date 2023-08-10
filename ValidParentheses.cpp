// Time: O(N)
// Space: O(N)

class Solution
{
public:
    bool isValid(string);
};

bool Solution::isValid(string s)
{
    unordered_map<char, char> close_open_bracket;
    close_open_bracket[')'] = '(';
    close_open_bracket['}'] = '{';
    close_open_bracket[']'] = '[';

    stack<char> st;

    for (const auto& c : s)
        if (!st.empty() && (close_open_bracket.find(c) != close_open_bracket.end()))
        {
            if (close_open_bracket[c] == st.top())
                st.pop();
            else
                return false;
        }
        else
            st.push(c);

    return st.empty() ? true : false;
}
