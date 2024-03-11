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
//某个区间全部加上k， 查询某个点的值
int n, q, a[N];
LL c[N]; //c代表的是下标管理的区间差分和

int lowbit(int x) {
    return x & (-x);
}

void add(int p, LL k) {
    for (; p <= n; p += lowbit(p)){
        c[p] += k;
    }
}

// 求单点p的值
LL ask(int p) {
    LL ans = 0;
    while (p) {
        ans += c[p];
        p -= lowbit(p);
    }
    return ans;
}


void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            add(l, k);
            add(r + 1, -k);
        }else {
            int x;
            cin >> x;
            cout << ask(x) << endl;
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