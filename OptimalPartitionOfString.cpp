class Solution {
public:
    int partitionString(string);
};

int Solution::partitionString(string s) {
    array<int, 26> last_seen;
    last_seen.fill(-1);
    int count = 1;
    int sub_string_start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (last_seen[s[i] - 'a'] >= sub_string_start) {
            count++;
            sub_string_start = i;
        }
        last_seen[s[i] - 'a'] = i;
    }

    return count;
}
