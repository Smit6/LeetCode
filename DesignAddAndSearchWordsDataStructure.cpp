struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode* cur = root;
        for (auto& c : word)
        {
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->is_end_of_word = true;
    }

    bool search(string word)
    {
        return dfs(root, 0, word);
    }
private:
    TrieNode* root;

    bool dfs(TrieNode* node, int j, const string& word)
    {
        TrieNode* cur = node;

        for (int i = j; i < word.length(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                for (auto k_v : cur->children)
                    if (dfs(k_v.second, i + 1, word))
                        return true;
                return false;
            }
            else
            {
                if (cur->children.find(c) == cur->children.end())
                    return false;
                cur = cur->children[c];
            }
        }

        return cur->is_end_of_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */