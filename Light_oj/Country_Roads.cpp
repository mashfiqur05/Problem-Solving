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
const int MX = 523;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<pair<int, int>> adj[MX];
ll dis[MX];
bool vis[MX];

void dijkstra(int source, int n)
{
    for (int i = 0; i <= n; i++) dis[i] = infLL;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    pq.push ({0, source});
    dis[source] = 0;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll node = x.second;
        if (vis[node]) continue;
        vis[node] = 1;

        for (auto y : adj[node])
        {
            ll v = y.first;
            ll w = y.second;
            if (max(w, dis[node]) < dis[v])
            {
                dis[v] = max (w, dis[node]);
                pq.push ({dis[v], v});
            }
        }
    }
}


void solve ()
{
    mem (vis, 0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back ({b, cost});   
        adj[b].push_back ({a, cost});
    }
    int mine; cin >> mine;
    dijkstra (mine, n-1);

    for (int i = 0; i < n; i++)
    {
        if (dis[i] == infLL) cout << "Impossible" << endl;
        else cout << dis[i] << endl;
    }
    for (int i = 0; i <= n; i++) adj[i].clear();
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