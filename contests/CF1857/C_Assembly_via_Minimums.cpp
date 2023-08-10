#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e3 + 10;
int b[N * N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n * (n - 1) / 2; i ++) cin >> b[i];
    sort(b + 1, b + 1 + n * (n - 1) / 2);

    int cnt = 1;
    for (int i = 1; i < n; i ++){
        cout << b[cnt] << ' ';
        cnt += n - i;
    } 
    cout << b[n * (n - 1) / 2] << endl;  
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