// DSU dsu(n)就行 下标从1开始 
struct DSU {
    std::vector<int> fa, sz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    // 合并 将x合并到y
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        sz[y] += sz[x];
        fa[x] = y;
        return true;
    }
    
    int size(int x) {
        return sz[find(x)];
    }
};
