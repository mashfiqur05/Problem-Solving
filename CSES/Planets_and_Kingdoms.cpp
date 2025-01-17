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

vector<int> adj[MX], rev_adj[MX], order;
vector<vector<int>> components;
bool vis[MX];
int n, m;

void dfs1 (int v)
{
    vis[v] = 1;
    for (auto child : adj[v])
    {
        if (vis[child]) continue;
        dfs1(child);
    }
    order.push_back (v);
}

void dfs2(int v, vector<int> &component)
{
    vis[v] = true;
    component.push_back(v); // Add vertex to the current SCC
    for (auto u : rev_adj[v])
    {
        if (!vis[u])
        {
            dfs2(u, component);
        }
    }
}

void solve (int testCase)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back (b);
        rev_adj[b].push_back (a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) dfs1 (i);
    }

    mem (vis, 0);
    reverse (all (order));
    components.clear();
    vector<int> kingdom(n+1, 0);
    int id = 1;

    for (auto u : order)
    {
        if (!vis[u])
        {
            vector<int> component;
            dfs2(u, component);
            components.push_back(component);

            for (auto node : component)
            {
                kingdom[node] = id;
            }
            id++;
        }
    }

    cout << --id << endl;
    for (int i = 1; i <= n; i++) cout << kingdom[i] << " "; cout << endl;
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