
///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///
 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
 
#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))
#define unq(x)                                        \
    {                                                 \
        x.erase(unique(x.begin(), x.end()), x.end()); \
    }
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9 + 7;
 
vector<int> g[MX];
int n;
int level[MX];
 
void dfs(int u, int p)
{
    for (int v : g[u])
    {
        if (v != p)
        {
            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }
}
 
void solve(int CaseNo)
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    level[1] = 0;
    dfs(1, 0);
 
    int node1 = 1, node2 = 1, mxDis = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mxDis < level[i])
        {
            mxDis = level[i];
            node1 = i;
        }
    }
    
    vector<int> ans(n+1, 0);
    mem (level, 0);
    dfs (node1, 0);
    mxDis = 0;
    
    for (int i = 1; i <= n; i++)
    {
        ans[i] = max (ans[i], level[i]);
        if (mxDis < level[i])
        {
            mxDis = level[i];
            node2 = i;
        }
    }

    mem (level, 0);
    dfs (node2, 0);
    
    for (int i = 1; i <= n; i++)
    {
        ans[i] = max (ans[i], level[i]);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}
 
int32_t main()
{
    fastio();
    // srand(time(NULL));
 
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve(tt);
    }
 
    return 0;
}
