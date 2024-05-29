#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
using a2 = array<int, 2>;
// cout << fixed << setprecision(7) << ans << endl;
const int mod = 998244353;
const int N = 120;
int w[N], v[N], f[N][N * 1000];
int n, W;

void solve() {
    cin >> n >> W;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= sum; i++)
        f[0][i] = 1e9;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++) {
            if (j >= v[i])
                f[i][j] = min(f[i - 1][j - v[i]] + w[i], f[i - 1][j]);
            else
                f[i][j] = f[i - 1][j];
        }

    for (int j = sum; j >= 0; j--) {
        if (f[n][j] <= W) {
            cout << j << endl;
            break;
        }
    }
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