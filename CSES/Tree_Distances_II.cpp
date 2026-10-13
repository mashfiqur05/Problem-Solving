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

int n, dp[N], sz[N];
vector<int> g[N];

void dfs1 (int node, int p)
{
    sz[node] = 0;
    dp[node] = 0;

    for (auto u : g[node])
    {
        if (u == p) continue;

        dfs1(u, node);

        sz[node] += sz[u] + 1;
        dp[node] += dp[u] + sz[u]+1;
    }
}

void dfs2 (int node, int p)
{
    for (auto u : g[node])
    {
        if (u == p) continue;

        dp[u] = dp[node] + n - 2 * (sz[u]+1);
        dfs2(u, node);
    }
}

void solve ()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 

    dfs1(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
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