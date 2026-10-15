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
const int N = 3e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> adj[N];

void solve ()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int u, v; cin >> u >> v;
        adj[u].push_back (v);
        adj[v].push_back (u);
    }
    
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 0)
        {
            cout << "Brain Melt" << endl;
            for (int i = 1; i <= n; i++) adj[i].clear();
            return;
        }
        else if (adj[i].size() == n-1) root++;
        // cout << i << " " << adj[i].size() << endl;
    }

    // cout << root << endl;
    if (root == 1 && m == n-1) cout << 2 << endl;
    else cout << "Many" << endl;

    for (int i = 1; i <= n; i++) adj[i].clear();
}
/*
1 2
1 3
1 4
3 4
*/

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