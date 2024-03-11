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
int n, q;
LL a[N];
struct Node {
	#define lc p << 1
	#define rc p << 1 | 1
	int l, r;
	LL sum, add; // ÀÁ±ê¼Ç
}tr[N * 4];

void pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {
	if (tr[p].add) {
		tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
		tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
		tr[p].add = 0;
	}
} 

void build(int p, int l, int r) {
	tr[p] = {l, r, a[l], 0};
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(p);
}

void update(int p, int l, int r, LL k) {
    if (l > r) return;
	if (tr[p].l >= l && tr[p].r <= r) {
		tr[p].sum = (tr[p].r - tr[p].l + 1) * k;
		tr[p].add += k;
		return;
	}
	int mid = (tr[p].l + tr[p].r) >> 1;
	pushdown(p);
	if (l <= mid) update(lc, l, r, k);
	if (r > mid) update(rc, l, r, k);
	pushup(p);
}

LL ask(int p, int l, int r) {
    if (l > r) return 0;
	if (tr[p].l >= l && tr[p].r <= r) return tr[p].sum;
	int mid = (tr[p].l + tr[p].r) >> 1;
	pushdown(p);
	LL ans = 0;
	if (l <= mid) ans += ask(lc, l, r);
	if (r > mid) ans += ask(rc, l, r);
	return ans;
}


void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            update(1, x, x, k);
        }else {
            int l, r;
            cin >> l >> r;
            cout << ask(1, l, r) << "\n";  
        }
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t --) solve();
    return 0;
}