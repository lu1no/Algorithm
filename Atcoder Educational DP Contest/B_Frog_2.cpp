#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
using a2 = array<int, 2>;
//cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353;
const int N = 2e5 + 10;
int n, k;
int h[N], f[N];


void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    f[1] = 0;
    for (int i = 2; i <= n; i ++) {
        f[i] = 1e9;
        for (int j = max(1, i - k); j < i; j ++) {
            f[i] = min(f[i], f[j] + abs(h[i] - h[j]));
        }
    }
    cout << f[n];
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}
