// Time: O((4^N)/sqrt(N))
// Space: O(N)

class Solution {
public:
    vector<string> generateParenthesis(int);
private:
    vector<char> stack;
    vector<string> results;

    void backtrack(int, int, int);
};

vector<string> Solution::generateParenthesis(int n) {
    backtrack(n, 0, 0);
    return results;
}

void Solution::backtrack(int n, int open_n, int close_n) {
    // Valid if open == closed == n
    if (open_n == n && close_n == n) {
        string result = "";
        for (char c : stack)
            result += c;
        results.push_back(result);
        return;
    }

    // Only add "(" if open < n
    if (open_n < n) {
        stack.push_back('(');
        backtrack(n, open_n + 1, close_n);
        stack.pop_back();
    }

    // Only add ")" if closed < open
    if (close_n < open_n) {
        stack.push_back(')');
        backtrack(n, open_n, close_n + 1);
        stack.pop_back();
    }
}
