// Time: O(C) - Checking every letter of every word O(C), O(U + min(U ^ 2, N)), U and N will always be lower than C
// Space : O(1) or O(U + min(U ^ 2, N))

class Solution {
public:
    string alienOrder(vector<string>&);
private:
    unordered_map<char, vector<char>> adj_list;
    vector<char> result;
    set<char> cycle, visited;

    bool dfs(char);
};

bool Solution::dfs(char c) {
    if (cycle.find(c) != cycle.end()) return false;
    if (visited.find(c) != visited.end()) return true;

    cycle.insert(c);
    visited.insert(c);

    for (char c : adj_list[c])
        if (!dfs(c))
            return false;

    cycle.erase(c);
    result.push_back(c);

    return true;
}

string Solution::alienOrder(vector<string>& words) {
    // Prepare adj list
    string w1, w2;
    int min_len = 0;

    for (const string& word : words)
        for (char c : word)
            adj_list[c] = vector<char>();

    for (int i = 0; i < words.size() - 1; i++) {
        w1 = words[i];
        w2 = words[i + 1];
        min_len = min(w1.size(), w2.size());

        if (w1.size() > min_len && w1.substr(0, min_len) == w2)
            return "";

        for (int j = 0; j < min_len; j++)
            if (w1[j] != w2[j]) {
                adj_list[w1[j]].push_back(w2[j]);
                break;
            }
    }

    // DFS
    for (auto& k_v : adj_list)
        if (!dfs(k_v.first))
            return "";

    // Alien Order
    string alien_order(result.begin(), result.end());
    reverse(alien_order.begin(), alien_order.end());
    return alien_order;
}
