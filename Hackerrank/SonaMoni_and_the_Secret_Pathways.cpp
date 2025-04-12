///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

const int MX = 5e5 + 5;  
vector<int> adj[MX];
ll sz[MX];
bool vis[MX];
int n;

long long dfs(int node)
{
    vis[node] = true; 
    sz[node] = 1;
    long long ret = 0;

    for (auto u : adj[node])
    {
        if (vis[u]) continue; 

        ret += dfs(u);

        ll tmp1 = sz[u];
        ll tmp2 = n - tmp1;
        ret += tmp1 * tmp2;

        sz[node] += sz[u];
    }

    return ret;
}

void testCases(int tt)
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
        sz[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = dfs(1);
    cout << 4 * ans << endl;
}

int32_t main()
{
    fastio();
    
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }

    return 0;
}
