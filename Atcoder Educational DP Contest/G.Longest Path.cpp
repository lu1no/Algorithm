#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod = 998244353, INF = 1 << 30;
const int N = 1e5 + 10;
int n, m;
int din[N], f[N];
vector<int> e[N], tp;

bool topsort()
{
    priority_queue<int,vector<int>,greater<int> > q; 
    for (int i = 1; i <= n; i ++) 
        if (din[i] == 0)  q.push(i);
    
    while (q.size()){
        int u = q.top(); q.pop();
        tp.push_back(u);
        for (int v: e[u]){
            din[v] --;
            if (din[v] == 0) q.push(v);
        }
    }
    return tp.size() == n;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        din[y] ++;
    }
    topsort();
    for (int i = 0; i < n; i ++){
        int u = tp[i];
        for (int j = 0; j < e[u].size(); j ++){
            int v = e[u][j];
            f[v] = max(f[v], f[u] + 1);
            // cout << v << ' ' << f[v] << endl;
        }
    }
    int res = -1;
    for (int i = 1; i <= n; i ++){
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}
