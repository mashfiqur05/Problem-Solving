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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> g[N];

int shortestPath(int n, int u, int v) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[u] = 0;
    q.push(u);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == v) return dist[x];
        for (int y : g[x]) {
            if ((x == u && y == v) || (x == v && y == u)) continue;
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
    return -1;
}

void solve()
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x != 0) v.push_back(x);   // zeros never form an edge
    }
    n = v.size();

    if (n > 120) {                    // pigeonhole: some bit is in >= 3 numbers
        cout << 3 << endl;
        return;
    }

    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if ((v[i] & v[j]) != 0) {
                g[i].push_back(j);
                g[j].push_back(i);
                edges.push_back({i, j});
            }

    if (edges.size() > 60) {          // some bit shared by >= 3 numbers
        cout << 3 << endl;
        return;
    }

    int ans = LLONG_MAX;
    for (auto [a, b] : edges) {
        int d = shortestPath(n, a, b);
        if (d != -1) ans = min(ans, d + 1);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}