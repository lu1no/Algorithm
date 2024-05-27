#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353, INF = 1 << 30;
const int N = 2e5 + 10;
int h[N], n;
int f[N];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    f[1] = 0;
    f[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= n; i ++) {
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << f[n] << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}
