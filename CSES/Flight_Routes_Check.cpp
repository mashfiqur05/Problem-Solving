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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, m;
vector<int> adj[MX], rev_adj[MX];
bool vis1[MX], vis2[MX];

void dfs1 (int v)
{
    vis1[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis1[u]) dfs1(u);
    } 
}
void dfs2 (int v)
{
    vis2[v] = 1;
    for (auto u : rev_adj[v])
    {
        if (!vis2[u]) dfs2(u);
    } 
}

void solve (int testCase)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back (a);
    }

    dfs1(1);
    dfs2 (1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis1[i] || !vis2[i])
        {
            cout << "NO" << endl;
            if (!vis1[i]) cout << 1 << " " << i << endl;
            else cout << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
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