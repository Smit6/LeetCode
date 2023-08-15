// Time: O(N.amortized(N)) = O(N)
// Space : O(N)

class UnionFind {
public:
    UnionFind(int);
    bool unionU(int, int);
private:
    unordered_map<int, int> parent;
    vector<int> rank;

    int find(int);
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>&);
};



UnionFind::UnionFind(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = i;
    rank = vector<int>(n, 0);
}

int UnionFind::find(int u) {
    if (u == parent[u])
        return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

bool UnionFind::unionU(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return 0;

    if (rank[u] > rank[v])
        parent[v] = u;
    else if (rank[u] < rank[v])
        parent[u] = v;
    else {
        parent[v] = u;
        rank[u]++;
    }

    return true;
}

vector<int> Solution::findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf = UnionFind(edges.size() + 1);

    for (vector<int>& edge : edges)
        if (!uf.unionU(edge[0], edge[1]))
            return edge;
    
    return vector<int>({ -1, -1 });
}
