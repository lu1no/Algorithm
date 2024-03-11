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
int n;
int a[N];

struct Node {
    #define lc p << 1
    #define rc p << 1 | 1
    int l, r;
    int sum;
}tr[N * 4];

void pushup(int p) {
    tr[p].sum = tr[lc].sum+ tr[rc].sum;
}

void build(int p, int l, int r) {
    tr[p] = {l, r, 1};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
} 

void update(int p, int x, int k) {
    if (tr[p].l == x && tr[p].r == x) {
        // 这里会变
        tr[p].sum += k;
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) update(lc, x, k);
    else update(rc, x, k); 
    pushup(p);    
}


int ask(int p, int l, int r, int k) {
    if (tr[p].l == tr[p].r) {
        return tr[p].l;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (k <= tr[lc].sum) {
        return ask(lc, l, mid, k);
    } else {
        return ask(rc, mid + 1, r, k - tr[lc].sum);
    }
}


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        int now = ask(1, 1, n, x);
        cout << a[now] << ' ';
        update(1, now, -1);
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t --) solve();
    return 0;
}