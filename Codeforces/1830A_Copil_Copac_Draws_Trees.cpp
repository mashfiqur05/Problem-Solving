///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int dp[MX], n, preRequisite[MX];
bool vis[MX];
vector<pair<int,int>> g[MX];

void dfs (int v)
{
    vis[v] = true;

    for (auto u : g[v])
    {
        if (vis[u.first]) continue;

        if (preRequisite[v] <= u.second)
        {
            dp[u.first] = dp[v];
            preRequisite[u.first] = u.second;
        }
        else 
        {
            dp[u.first] = dp[v] + 1;
            preRequisite[u.first] = u.second;
        }

        dfs (u.first);
    }
}

void testCases (int tt)
{
    cin >> n;
    mem (vis, 0);
    mem (dp, 0);
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back ({v, i});
        g[v].push_back ({u, i});
    }

    dp[1] = 1;
    preRequisite[1] = 0;
    dfs (1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}