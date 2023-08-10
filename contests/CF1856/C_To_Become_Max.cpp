#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
int a[N];
int n, k;

LL check(int idx, int mid)
{
    LL cnt = 0;
    int x = mid;
    for (int i = idx; i <= n; i ++){
        if (a[i] >= x) break;
        if (i == n) return 1e9;
        cnt += 1LL * (x - a[i]); //这里可能非常大爆int
        x --;
    }
    return cnt;
}

void solve()
{
    cin >> n >> k;
    int res = -1;
    for (int i = 1; i <= n; i ++) {cin >> a[i];}
    
    for (int i = 1; i < n; i ++){
        int l = a[i], r = a[i] + k;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (check(i, mid) > k) r = mid - 1;
            else l = mid + 1;
        }
        res = max(r, res);
    }
    cout << max(res, a[n]) << endl;
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