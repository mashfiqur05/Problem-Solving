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

vector<int> g[MX];
bool vis[MX];
int n, m, prev_node[MX], st_node, end_node;
bool isLoopExists = false;

bool cycleDetection (int vertex, int par = 0)
{
    prev_node[vertex] = par;
    vis[vertex] = true;

    for (auto child : g[vertex])
    {
        if (child == par) continue;
        if (vis[child]) 
        {
            if (!isLoopExists)
            {
                st_node = vertex;
                end_node = child;
                isLoopExists = true;
            }
            return true;
        }

        isLoopExists |= cycleDetection (child, vertex); // or equal
    }

    return isLoopExists;
}

void solve (int CaseNo)
{
    cin >> n >> m;  
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    bool f = false;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) f |= cycleDetection (i);
    }

    // cout << "st " << st_node << " end " << end_node << endl;
    // for (int i = 1; i <= n; i++) cout << i << "---->" << prev_node[i] << endl;
    if (!f) cout << "IMPOSSIBLE" << endl;
    else 
    {
        vector<int> ans;
        int cur = st_node;
        while (cur != prev_node[end_node])
        {
            ans.push_back (cur);
            cur = prev_node[cur];
        }
        reverse(all (ans));
        ans.push_back (ans[0]);
        cout << ans.size() << endl;
        for (auto u : ans) cout << u << " "; cout << endl;
    }
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