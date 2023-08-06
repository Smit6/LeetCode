class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

    int uf_find(int v)
    {
        if (v == parent[v]) return v;
        parent[v] = uf_find(parent[v]);
        return parent[v];
    }
public:
    UnionFind(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        rank = vector<int>(n, 0);
    }

    int uf_union(int v1, int v2)
    {
        v1 = uf_find(v1);
        v2 = uf_find(v2);

        if (v1 == v2) return 0;

        if (rank[v1] > rank[v2])
            parent[v2] = v1;
        else if (rank[v1] < rank[v2])
            parent[v1] = v2;
        else
        {
            parent[v2] = v1;
            rank[v1]++;
        }
        return 1;
    }
};

class Solution
{
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        UnionFind* uf = new UnionFind(n);
        for (auto& edge : edges)
            n -= uf->uf_union(edge[0], edge[1]);
        return n;
    }
};