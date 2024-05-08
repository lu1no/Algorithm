// 没有卡自然溢出 非常有素质
// 卡了换随机底数 + 孪生素数双哈希
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int mod = 998244353, INF = 1 << 30;
const ULL P = 131;
const int N = 1e6 + 10;
ULL p[N];
int n, q;
string s;
struct node {
    #define lc u << 1
    #define rc u << 1 | 1
    int l, r;
    ULL h1, h2; // 左哈希 右哈希
} tr[N * 4];

void pushup(int u) {
    int len1 = (tr[rc].r - tr[rc].l + 1);
    int len2 = (tr[lc].r - tr[lc].l + 1);
    tr[u].h1 = tr[lc].h1 * p[len1] + tr[rc].h1;
    tr[u].h2 = tr[lc].h2 + tr[rc].h2 * p[len2];
}

void build(int u, int l, int r) {
    tr[u] = {l, r, ULL(s[l]), ULL(s[l])};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(u);
}

// 左
ULL ask1(int u, int x, int y) {
    if (x <= tr[u].l && y >= tr[u].r) {
        return tr[u].h1 * p[y - tr[u].r]; // why?
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    ULL sum = 0;
    if (x <= mid)
        sum += ask1(lc, x, y);
    if (y > mid)
        sum += ask1(rc, x, y);
    return sum;
}

// 右
ULL ask2(int u, int x, int y) {
    if (x <= tr[u].l && y >= tr[u].r) {
        return tr[u].h2 * p[tr[u].l - x]; // why?
    }

    int mid = (tr[u].l + tr[u].r) >> 1;
    ULL sum = 0;
    if (x <= mid)
        sum += ask2(lc, x, y);
    if (y > mid)
        sum += ask2(rc, x, y);
    return sum;
}

// 点更新
void update(int u, int x, ULL k) {
    if (tr[u].l == tr[u].r) {
        tr[u].h1 = tr[u].h2 = k;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid)
        update(lc, x, k);
    else
        update(rc, x, k);
    pushup(u);
}

void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P;
}

void solve() {
    init();
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    build(1, 1, n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            char c;
            cin >> x >> c;
            update(1, x, ULL(c));
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            bool ok = ask1(1, l, r) == ask2(1, l, r);
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
