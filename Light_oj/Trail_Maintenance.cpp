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

int parent[223];
int sz[223];

int findParent(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void make_union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

void solve()
{

    int n, ed;
    cin >> n >> ed;
    multiset<pair<int, pair<int, int>>> edge;

    for (int i = 0; i < ed; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.insert({w, {u, v}});

        int mnST = 0, cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }

        for (auto e : edge)
        {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            u = findParent(u);
            v = findParent(v);

            if (u != v)
            {
                cnt++;
                mnST += w;
                make_union(u, v);
            }
            if (cnt == n - 1)
                break;
        }

        if (cnt != n-1) cout << -1 << endl;
        else cout << mnST << endl;
    }
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ":" << endl;
        solve ();
    }

    return 0;
}