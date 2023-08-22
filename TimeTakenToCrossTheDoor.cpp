// Time: O(N)
// Space: O(N)

class Solution {
public:
    vector<int> timeTaken(vector<int>&, vector<int>&);
};

vector<int> Solution::timeTaken(vector<int>& arrival, vector<int>& state) {
    queue<int> q[2];
    int n = state.size();
    int i = 0;
    int dir = 1; // Exit goes frist
    int time = 0;

    vector<int> result;
    result.resize(n);

    while (n - i + q[0].size() + q[1].size()) {
        while (i < n && arrival[i] <= time)
            q[state[i]].push(i++);
        
        dir = q[0].empty() ? 1 : q[1].empty() ? 0 : dir;

        if (q[dir].size()) {
            result[q[dir].front()] = time;
            q[dir].pop();
        }
        time++;
    }

    return result;
}
