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
int h[N], r[N];
int n, m;

// 查询区间最大值 + 单点修改
struct Node {
    #define lc p << 1
    #define rc p << 1 | 1
    int l, r;
    int mx;
}tr[N * 4];

void pushup(int p) {
    tr[p].mx = max(tr[lc].mx, tr[rc].mx);
}

void build(int p, int l, int r) {
    tr[p] = {l, r, h[l]};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
} 

void update(int p, int x, int k) {
    if (tr[p].l == x && tr[p].r == x) {
        // 这里会变
        tr[p].mx = max(0, tr[p].mx + k);
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) update(lc, x, k);
    else update(rc, x, k); 
    pushup(p);    
}

int ask(int p, int l, int r, int k) {
    if (tr[p].l == tr[p].r) {
        if (tr[p].mx < k) return 0;
        else return tr[p].l;
    }
    int ans = 0;
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (tr[lc].mx >= k) ans = ask(lc, l, r, k);
    else ans = ask(rc, l, r, k);
    return ans;
}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i ++) {
        int k;
        cin >> k;
        int now = ask(1, 1, n, k);
        if (now) update(1, now, -k);
        cout << now << ' ';
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t --) solve();
    return 0;
}