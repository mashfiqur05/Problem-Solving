///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> g[N];
int n, dp[N], s[N], a[N], sz[N], total;

void dfs1(int node = 1, int par = 0)
{
    s[node] = a[node];
    dp[node] = 0;
    for (auto u : g[node])
    {
        if (u == par) continue;
        dfs1 (u, node);

        s[node] += s[u];
        dp[node] += dp[u] + s[u]; 
        // cout << node <<  " " << u << " " << s[node] << endl;
    }
}

void dfs2 (int node = 1, int par = 0)
{
    for (auto u : g[node])
    {
        if (u == par) continue;
        dp[u] = dp[node] +total - 2 * s[u];

        dfs2(u, node);
    }
}

void solve ()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i]; total += a[i];}
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // cout << total << endl;
    dfs1();
    dfs2();
    // cout << dp[1] << endl;
    // for (int i = 1; i <= n; i++) cout << i << " " << dp[i] << " " << s[i] << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max (ans, dp[i]);
    cout << ans << endl;
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}