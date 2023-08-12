class Solution {
public:
    int ladderLength(string, string, vector<string>&);
private:
    set<string> word_set;
    unordered_map<string, vector<string>> adj_list;
    deque<string> q;
    set<string> visited;
};

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;
    word_set = set<string>(wordList.begin(), wordList.end());
    word_set.insert(beginWord);

    for (auto& word : wordList)
        for (int i = 0; i < word.length(); i++) {
            adj_list[word.substr(0, i) + "." + word.substr(i + 1, word.length() - 1 - i)].push_back(word);
        }

    q.push_back(beginWord);
    int result = 0;
    int q_size = 0;
    string word;
    string pattern;
    while (q.size())
    {
        q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            word = q.front();
            q.pop_front();
            if (word == endWord)
                return result + 1;

            for (int j = 0; j < word.size(); j++) {
                pattern = word.substr(0, j) + "." + word.substr(j + 1, word.length() - 1 - j);
                for (auto& adj_word : adj_list[pattern])
                    if (visited.find(adj_word) == visited.end()) {
                        visited.insert(adj_word);
                        q.push_back(adj_word);
                    }
            }
        }
        cout << "Came" << q.size() << endl;
        result++;
    }
    return 0;
}
