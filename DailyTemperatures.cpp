// Time: O(N)
// Space: O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>&);
};

vector<int> Solution::dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(), 0);
    vector<pair<int, int>> st;

    for (int day = 0; day < temperatures.size(); day++) {
        while (st.size() && st.back().first < temperatures[day]) {
            ans[st.back().second] = day - st.back().second;
            st.pop_back();
        }
        st.push_back(make_pair(temperatures[day], day));
    }

    return ans;
}