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

/*
dp[node][0] not connected with node-child
dp[node][1] connected.

dp[node][0] = dp[c1][1] + dp[c2][1] + ... for all child
dp[node][1] = dp[child][0] + 1 + dp[allOtherChild][1].
            = dp[child][0] + 1 + dp[node][0] - dp[child][0].

*/

int n, dp[N][2];
vector<int> g[N];

void dfs (int node, int par)
{
    for (auto child : g[node])
    {
        if (child == par) continue;

        dfs (child, node);

        dp[node][0] += max (dp[child][0], dp[child][1]);

        // dp[node][1] = max (dp[node][1], dp[child][0] + 1 + dp[node][0] - max (dp[child][0], dp[child][1]));
    }
    for (auto child : g[node])
    {
        if (child == par) continue;

        dp[node][1] = max (dp[node][1], dp[child][0] + 1 + dp[node][0] - max (dp[child][0], dp[child][1]));
    }
}

void solve ()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    dfs (1, 0);

    cout << max (dp[1][0], dp[1][1]) << endl;
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