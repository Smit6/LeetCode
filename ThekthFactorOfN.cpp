// Time: O(sqrt(N))
// Space: O(sqrt(N))

class Solution {
public:
    int kthFactor(int, int);
};

int Solution::kthFactor(int n, int k) {
    vector<int> smaller;
    vector<int> higher;

    int range = sqrt(n);

    for (int i = 1; i <= range; i++) {
        if (n % i == 0) {
            if (i * i == n)
                smaller.push_back(i);
            else {
                smaller.push_back(i);
                higher.push_back(n / i);
            }
        }
    }

    smaller.insert(smaller.end(), higher.rbegin(), higher.rend());
    if (k > smaller.size())
        return -1;
    
    return smaller[k - 1];
}