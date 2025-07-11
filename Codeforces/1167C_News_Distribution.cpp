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
const int MX = 5e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, m, nodeCnt = 0;
vector<int> g[MX], curNode;
bool vis[MX];

void dfs (int vertex)
{
    vis[vertex] = 1;
    curNode.push_back (vertex);
    nodeCnt++;

    for (auto u : g[vertex])
    {
        if (vis[u]) continue;
        dfs (u);
    }
}


void solve (int CaseNo)
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int j = 0; j < k; j++)
        {
            cin >> v[j];
            if (j != 0) 
            {
                g[v[j-1]].push_back (v[j]);
                g[v[j]].push_back (v[j-1]);
            }
        }
    }

    vector<int> ans (n+1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) 
        {
            nodeCnt = 0;
            curNode.clear();
            dfs (i);
            int val = nodeCnt;
            
            for (auto u : curNode) ans[u] = val;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
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