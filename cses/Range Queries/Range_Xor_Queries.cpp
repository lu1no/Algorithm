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
int pre[N];
int n, q;



void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> pre[i];
        pre[i] ^= pre[i - 1];
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << (pre[r] ^ pre[l - 1]) << endl;
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    while(t --) solve();
    return 0;
}