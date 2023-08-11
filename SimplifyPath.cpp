class Solution {
public:
    string simplifyPath(string);
};

string Solution::simplifyPath(string path) {
    stack<string> directories;
    string res;

    stringstream ss(path);
    string directory;

    string one_dot = ".";
    string two_dot = "..";

    while (getline(ss, directory, '/')) {
        if (directory.empty() || directory == one_dot)
            continue;
        else if (directory == two_dot) {
            if (directories.size())
                directories.pop();
        }
        else
            directories.push(directory);
    }

    while (!directories.empty())
    {
        res = "/" + directories.top() + res;
        directories.pop();
    }


    if (res.size() == 0)
        return "/";

    return res;
}