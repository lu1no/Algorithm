#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
using a2 = array<int, 2>;
// cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353;
const int N = 2e5 + 10;
int a[N], b[N], c[N];
int f[N][3];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][1], f[i - 1][2]) + a[i];
        f[i][1] = max(f[i - 1][0], f[i - 1][2]) + b[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][1]) + c[i];
    }

    int res = 0;
    for (int i = 0; i < 3; i++)
        res = max(res, f[n][i]);
    cout << res << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}