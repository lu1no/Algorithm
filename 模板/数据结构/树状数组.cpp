template <typename T> struct Fenwick {
    int n;
    vector<T> a;
    Fenwick(int n = 0) { init(n); }
    void init(int n) {
        this->n = n;
        a.assign(n + 1, T());
    }
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i)
            a[i] += v;
    }
    T sum(int x) {
        auto ans = T();
        for (int i = x; i; i -= i & -i)
            ans += a[i];
        return ans;
    }
    T rangeSum(int l, int r) { return sum(r) - sum(l - 1); }
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i >>= 1) {
            if (x + i <= n && k >= a[x + i]) {
                x += i;
                k -= a[x];
            }
        }
        return x;
    }
};
