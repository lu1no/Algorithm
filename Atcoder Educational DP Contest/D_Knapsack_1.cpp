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
int n, W;
LL w[N], v[N];
LL f[N];


void solve() {
    cin >> n >> W;
    for (int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    // f(i, j) = MAX[f(i - 1, j), f(i - 1, j - w[i]) + v[i]]
    for (int i = 1; i <= n; i ++) {
        for (int j = W; j >= w[i]; j --) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[W] << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}