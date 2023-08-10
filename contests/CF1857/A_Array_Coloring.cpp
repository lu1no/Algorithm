#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;


void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1;i <= n; i ++){
        int x;
        cin >> x;
        sum += x;
    }
    if (sum % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl; 
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