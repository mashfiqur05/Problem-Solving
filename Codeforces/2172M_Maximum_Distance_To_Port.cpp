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

int n, m, k;
vector<int>g[MX];
vector<int> productId(MX), ans(MX), level(MX, 0);
bool vis[MX];

void bfs (int source)
{
    queue<int> q;
    q.push (source);
    vis[source] = true;
    level[source] = 0;
    ans[productId[source]] = max (ans[productId[source]], level[source]);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto u : g[node])
        {
            if (vis[u]) continue;
            q.push (u);
            level[u] = level[node] + 1;
            ans[productId[u]] = max (ans[productId[u]], level[u]);
            vis[u] = true;
        }
    }
}

void solve (int CaseNo)
{
    cin >> n >> m >> k;
    productId.resize(n+1);
    ans.resize(k+1, 0);
    for (int i = 1; i <= n; i++) cin >> productId[i];
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    bfs (1);

    for (int i = 1; i <= k; i++) cout << ans[i] << " "; cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}