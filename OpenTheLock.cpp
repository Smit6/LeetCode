

class Solution {
public:
    int openLock(vector<string>&, string);
private:
    vector<string> get_children(const string&);
};

vector<string> Solution::get_children(const string& lock) {
    vector<string> children;
    for (int i = 0; i < 4; i++) {
        string child = lock;
        child[i] = (child[i] - '0' + 1) % 10 + '0';
        children.push_back(child);
        child[i] = (child[i] - '0' + 8) % 10 + '0';
        children.push_back(child);
    }
    return children;
}

int Solution::openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited;

    for (auto& deadend : deadends) {
        if (deadend == "0000")
            return -1;
        visited.insert(deadend);
    }
    
    deque<pair<string, int>> q; // Lock, Turns
    q.push_back({"0000", 0});

    while (!q.empty()) {
        auto [lock, turns] = q.front();
        q.pop_front();

        if (lock == target)
            return turns;
        
        auto children = get_children(lock);
        for (auto& child : children) {
            if (!visited.contains(child)) {
                visited.insert(child);
                q.push_back({child, turns + 1});
            }
        }
    }

    return -1;
}
