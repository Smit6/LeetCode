// Time: O(M) for well defined words, O(N*(26^M)) for undefined words
// Space: O(1) for well defined words, O(M) for undefined words (to keep recursion stack)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
};

class WordDictionary {
public:
    WordDictionary();
    void addWord(string);
    bool search(string);
private:
    TrieNode* root;
    bool dfs(TrieNode*, int, const string&);
};


WordDictionary::WordDictionary() {
    root = new TrieNode();
}

void WordDictionary::addWord(string word) {
    TrieNode* cur = root;
    for (auto c : word) {
        if (cur->children.find(c) == cur->children.end())
            cur->children[c] = new TrieNode();
        cur = cur->children[c];
    }
    cur->is_end_of_word = true;
}

bool WordDictionary::dfs(TrieNode* node, int j, const string& word) {
    TrieNode* cur = node;
    
    for (int i = j; i < word.length(); i++) {
        char c = word[i];
        if (c == '.') {
            for (auto& [k_c, v_node] : cur->children)
                if (dfs(v_node, i + 1, word))
                    return true;
            return false;
        } else {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
    }

    return cur->is_end_of_word;
}

bool WordDictionary::search(string word) {
    return dfs(root, 0, word);
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */