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

int n, c[N], dp[N][2];
vector<int> g[N];

void dfs (int node, int p)
{   
    if (c[node])
    {
        dp[node][1] = 1;
        dp[node][0] = 0;
    } 
    else 
    {
        dp[node][1] = 0;
        dp[node][0] = 1;
    }

    for (auto u : g[node])
    {
        if (u == p) continue;

        dfs (u, node);

        int S = (dp[u][0] + dp[u][1]) % MOD;

        int one  = (dp[node][1] * S + dp[node][0] * dp[u][1]) % MOD;
        int zero = (dp[node][0] * S) % MOD;

        dp[node][1] = one;
        dp[node][0] = zero;
    }
}

void solve ()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u; cin >> u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    for (int i = 0; i < n; i++) cin >> c[i];

    dfs(0,-1);
    int ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << dp[0][1] << endl;
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