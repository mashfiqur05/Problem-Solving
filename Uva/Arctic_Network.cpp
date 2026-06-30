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

int parent[523];
int sz[523];

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


void solve ()
{
    int s, ed;
    cin >> s >> ed;
    vector<pair<int,int>> v(ed);
    for (int i = 0; i < ed; i++) cin >> v[i].first >> v[i].second;

    vector<pair<double, pair<int, int>>> edge;
    for (int i = 0; i < ed; i++)
    {
        for (int j = i+1; j < ed; j++)
        {
            double dx = v[i].first - v[j].first;
            double dy = v[i].second - v[j].second;

            double d = sqrt(dx * dx + dy * dy);

            edge.push_back({d, {i, j}});
        }
    }

    int cnt = 0;

    for (int i = 0; i <= ed; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    sort (all (edge));

    vector<double> ans;
    for (auto e : edge)
    {
        int u = e.second.first;
        int v = e.second.second;
        double w = e.first;

        u = findParent(u);
        v = findParent(v);

        if (u != v)
        {
            cnt++;
            make_union(u, v);
            ans.push_back (w);
        }
        if (cnt == ed - 1)
            break;
    }

    sort (all (ans));
    cout << fixed << setprecision(2) << ans[ed-s-1] << endl;
}


int32_t main()
{
    fastio();
    fraction();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}