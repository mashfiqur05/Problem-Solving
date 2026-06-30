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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, k; 
vector<int> adj[MX];
int vis[MX], black[MX];
int cur = 0;

void dfs (int vertex)
{
    vis[vertex] = 1;
    cur++;

    for (auto child : adj[vertex])
    { 
        if (vis[child]) continue;
        dfs (child);    
    }
}
long long bigmod(long long a, long long b) {
    long long res = 1;

    while(b > 0) {
        if(b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

void solve ()
{
    cin >> n >> k;
    for (int i = 0; i < n-1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if (c == 1) {
            continue;
        }
        adj[u].push_back (v);
        adj[v].push_back (u);
    }

    vector<int> nk(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        nk[i] = bigmod(i, k);
    }

    int bad = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cur = 0;
            dfs (i);
            bad += nk[cur];
            bad %= MOD;
        }
    }

    int ans = (nk[n] - bad + MOD) % MOD;
    cout << ans << endl;
}


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}