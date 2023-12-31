struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word = false;
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
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
        TrieNode* cur = root;
        for (auto& c : word)
        {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return cur->is_end_of_word;
    }

    bool startsWith(string prefix)
    {
        TrieNode* cur = root;
        for (auto& c : prefix)
        {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */