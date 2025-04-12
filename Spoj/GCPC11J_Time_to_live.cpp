#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed, ios::floatfield);
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 1e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> g[MX];
int depth[MX];

void dfs(int vertex, int parent = -1)
{
    for (auto child : g[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

void testCases(int tt)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        g[i].clear();
    }
    mem(depth, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    int mx_depth = -1, node;
    for (int i = 0; i < n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
            node = i;
        }
    }

    mem(depth, 0);
    dfs(node);

    mx_depth = -1;
    for (int i = 0; i < n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
        }
    }

    // cout << mx_depth << " " << node << endl;
    int ans = (mx_depth + 1) / 2;
    cout << ans << endl;
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }

    return 0;
}
