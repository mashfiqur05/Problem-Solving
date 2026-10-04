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
const int N = 50000+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, k, dp[N][505], ans = 0;
vector<int> g[N];

void dfs (int node, int par)
{
    dp[node][1] = 1;
    dp[node][0] = 0;
    for (auto u : g[node])
    {
        if (u == par) continue;

        dfs (u, node);

        for (int i = 1; i <= k; i++)
        {
            if (k - i + 1 >= 0 && k - i + 1 < 505)
                ans += (dp[u][k - i + 1] * dp[node][i]);
        }
        for (int i = 1; i <= k; i++)
        {
            dp[node][i] += dp[u][i - 1];
        }
    }

    ans += dp[node][k+1];
}

void solve ()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    dfs (1, 0);

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