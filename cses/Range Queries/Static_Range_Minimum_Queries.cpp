#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353, INF = 1 << 30;
const int N = 2e5 + 10;
int a[N];
// 查询区间最大值 + 单点修改
struct Node {
    #define lc p << 1
    #define rc p << 1 | 1
    int l, r;
    int mn;
}tr[N * 4];

void pushup(int p) {
    tr[p].mn = min(tr[lc].mn, tr[rc].mn);
}

void build(int p, int l, int r) {
    tr[p] = {l, r, a[l]};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
} 

void update(int p, int x, int k) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p].mn = min(tr[p].mn, k);
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) update(lc, x, k);
    else update(rc, x, k); 
    pushup(p);    
}

int ask(int p, int l, int r) {
    if (l <= tr[p].l && r >= tr[p].r) return tr[p].mn;
    int mid = (tr[p].l + tr[p].r) >> 1;
    int ans = INF;
    if (l <= mid) ans = min(ask(lc, l, r), ans);
    if (r > mid) ans = min(ask(rc, l, r), ans);
    return ans;
}


void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << ask(1, l, r) << endl;
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t --) solve();
    return 0;
}