class Solution {
public:
    int largestRectangleArea(vector<int>&);
};

int Solution::largestRectangleArea(vector<int>& heights) {
    int largest_area = 0;
    stack<pair<int, int>> st;
    pair<int, int> p_c_h;

    int start_i;
    int c_i, c_h;

    int heights_size = heights.size();

    for (int i = 0; i < heights.size(); i++) {
        start_i = i;
        while (!st.empty() && st.top().second > heights[i]) {
            c_i = st.top().first;
            c_h = st.top().second;
            st.pop();
            largest_area = max(largest_area, c_h * (i - c_i));
            start_i = c_i;
        }
        st.push(make_pair(start_i, heights[i]));
    }

    while (!st.empty()) {
        p_c_h = st.top();
        st.pop();
        largest_area = max(largest_area, (heights_size - p_c_h.first) * p_c_h.second);
    }

    return largest_area;
}
