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

vector<pair<int, int>> adj[MX];
set<int> st;
bool f = false;

void dfsFromA (int node, int par, int xr, int b)
{
    if (node == b) return;

    st.insert (xr);

    for (auto child : adj[node])
    {
        int u = child.first, w = child.second;
        if (u == par) continue;

        dfsFromA(u, node, xr^w, b);
    }
}

void dfsFromB(int node , int par, int xr, int b)
{
    if (node != b && st.count(xr))
    {
        f = true;
        return;
    }

    for (auto child : adj[node])
    {
        int u = child.first, w = child.second;
        if (u == par || f) continue;

        dfsFromB(u, node, xr^w, b);
    }
}

void solve ()
{
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0; i < n-1; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back ({v, w});
        adj[v].push_back ({u, w});
    }

    st.clear();
    f = false;

    dfsFromA(a, -1, 0, b);
    dfsFromB(b, -1, 0, b);

    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    
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