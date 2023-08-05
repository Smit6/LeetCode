class Solution {
private:
    vector<char> ret;
    unordered_map<char, vector<char>> adj_list;
    set<char> visited, cycle;

    bool dfs(char c) {
        if (cycle.find(c) != cycle.end()) return false;
        if (visited.find(c) != visited.end()) return true;

        cycle.insert(c);
        visited.insert(c);

        for (auto ch : adj_list[c]) {
            if (!dfs(ch)) return false;
        }

        cycle.erase(c);
        ret.push_back(c);
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        int num_words = words.size();
        string w1, w2;
        int min_len, w1_len, w2_len;

        for (auto& word : words)
            for (auto& c : word)
                adj_list[c] = vector<char>();
        
        
        for (int i = 0; i < num_words - 1; i++) {
            w1 = words[i], w2 = words[i + 1];
            w1_len = w1.length(), w2_len = w2.length();
            min_len = min(w1_len, w2_len);

            if (w1_len > w2_len && w1.substr(0, min_len) == w2)
                return "";

            for (int j = 0; j < min_len; j++) {
                if (w1[j] != w2[j]) {
                    adj_list[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }

        for (auto& key_value : adj_list) {
            if (!dfs(key_value.first)) return "";
        }

        string result(ret.begin(), ret.end());
        reverse(result.begin(), result.end());
        return result;
    }
};