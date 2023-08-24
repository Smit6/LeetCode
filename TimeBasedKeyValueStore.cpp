class TimeMap {
public:
    TimeMap();
    void set(string, string, int);
    string get(string, int);
private:
    unordered_map<string, vector<pair<int, string>>> cache;
};

TimeMap::TimeMap() {

}

// Time: O(L*M), L = string length, M = number of SET calls
// Space: O(L*M)
void TimeMap::set(string key, string value, int timestamp) {
    cache[key].push_back(make_pair(timestamp, value));
}


// Time: O(N*L*logM), L = string length, N = number of GET calls, M = number of SET calls
// Space: O(1)
string TimeMap::get(string key, int timestamp) {
    if (!cache.contains(key))
        return "";
    
    if (timestamp < cache[key][0].first)
        return "";
    
    int left = 0;
    int right = cache[key].size();

    while (left < right) {
        int mid = (left + ((right - left) / 2));
        if (cache[key][mid].first <= timestamp)
            left = mid + 1;
        else
            right = mid;
    }

    return right == 0 ? "" : cache[key][right - 1].second;
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */