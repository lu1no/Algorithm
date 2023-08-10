#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int a[N], b[N], res[N];


void solve()
{
    int n;
    cin >> n;
    int mx = -2e9;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) {res[i] = a[i] - b[i]; mx = max(res[i], mx);}
    
    // cout << mx << endl;
    vector<int> ans;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (res[i] == mx) {cnt ++; ans.push_back(i);}
    }
    cout << cnt << endl;
    for (int x: ans) cout << x << ' ';
    cout << endl;
}


int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}