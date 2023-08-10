#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int a[N];

void solve()
{
    string x;
    cin >> x;
    x = '0' + x;
    int len = x.size();
    for (int i = 0; i < len; i ++){
        a[i] = int(x[i] - '0');
    }
    int res = len - 1;
    for (int i = len - 1; i >= 1; i --){
        if (a[i] >= 5) {a[i - 1] ++; res = min(res, i - 1);}
    }
    if (a[0] != 0) cout << a[0];
    for (int i = 1; i <= res; i ++) cout << a[i];
    for (int i = res + 1; i < len; i ++) cout << 0;
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