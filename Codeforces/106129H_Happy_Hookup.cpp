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
bool visForA[MX], visForB[MX];
int n, m, a, b;

void dfs1 (int vertex)
{
    visForA[vertex] = true;

    for (auto u : g[vertex])
    {
        if (visForA[u]) continue;
        dfs1 (u);
    }
}

void dfs2 (int vertex)
{
    visForB[vertex] = true;

    for (auto u : g[vertex])
    {
        if (visForB[u]) continue;
        dfs2 (u);
    }
}

void solve (int CaseNo)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
    }
    cin >> a >> b;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "node " << i << ":  " ;
    //     for (auto u : g[i]) cout << u << ' ';
    //     cout << endl;
    // }
    dfs1 (a);   
    // for (int i = 1; i <= n; i++) cout << i << " " << visForA[i] << endl;
    dfs2 (b);
    // for (int i = 1; i <= n; i++) cout << i << " " << visForB[i] << endl;


    for (int i = 1; i <= n; i++)
    {
        if (visForA[i] && visForB[i])
        {
            cout << "yes" << endl << i << endl;
            return;
        }
    }
    cout << "no" << endl;
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