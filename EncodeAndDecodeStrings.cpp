class Codec
{
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs)
    {
        string result = "";
        for (auto& s : strs)
            result += s + '\0';
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        stringstream ss(s);
        vector<string> res;
        string tmp;
        while (getline(ss, tmp, '\0'))
            res.push_back(tmp);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));