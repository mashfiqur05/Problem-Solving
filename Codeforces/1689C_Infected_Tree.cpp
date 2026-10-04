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
const int N = 3e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/// 0 - not delet, 1 - delet
/*
dp[node][0] += dp[c][1]+1;
dp[node][1] = max (dp[c1][0], dp[c2][0])
*/
int n, dp[N], ch[N];
vector<int> g[N];

void dfs(int p, int q)
{
    ch[p]=1,dp[p]=0; int s=0;
    for (auto it : g[p]) if (it!=q)
    {
        dfs(it,p); s+=dp[it];
        ch[p]+=ch[it];
    }
    for (auto it : g[p]) if (it!=q)
    {
        dp[p]=max(dp[p],s-dp[it]+ch[it]-1);
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

    cout << dp[1] << endl;
    for (int i = 1; i <= n; i++)g[i].clear();
    mem (dp, 0);
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}