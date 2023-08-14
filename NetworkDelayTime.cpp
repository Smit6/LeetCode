// Time: O(E.logV)
// Space : O(V ^ 2)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>&, int, int);
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    unordered_map<int, vector<pair<int, int>>> adj_list;
    set<int> visited;
};

int Solution::networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int time = 0;
    pair<int, int> w_v;
    for (auto& u_v_w : times)
        adj_list[u_v_w[0]].push_back(make_pair(u_v_w[2], u_v_w[1]));

    heap.push(make_pair(0, k));

    while (!heap.empty()) {
        w_v = heap.top();
        heap.pop();
        if (visited.find(w_v.second) == visited.end()) {
            visited.insert(w_v.second);
            time = max(time, w_v.first);

            for (auto& adj_w_v : adj_list[w_v.second])
                heap.push(make_pair(w_v.first + adj_w_v.first, adj_w_v.second));
        }
    }

    return visited.size() == n ? time : -1;
}
