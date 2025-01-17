    //In the name of ALLAH

    #include<bits/stdc++.h>
    using namespace std;


    #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define MOD 1000000007
    #define MOD1 998244353
    #define INF 1e18
    #define endl "\n"
    #define pb push_back
    #define ppb pop_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define PI 3.141592653589793238462
    #define set_bits __builtin_popcountll
    #define sz(x) ((int)(x).size())
    #define mem(a,b) memset(a, b, sizeof(a) )
    #define sq(a) ((a) * (a))
    #define all(v) (v).begin(),(v).end()     /// ascending
    #define rall(v) (v).rbegin(),(v).rend()  /// descending


    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double lld;


    #ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
    #else
    #define debug(x)
    #endif

    void _print(ll t) {cerr << t;}
    void _print(int t) {cerr << t;}
    void _print(string t) {cerr << t;}
    void _print(char t) {cerr << t;}
    void _print(lld t) {cerr << t;}
    void _print(double t) {cerr << t;}
    void _print(ull t) {cerr << t;}

    template <class T, class V> void _print(pair <T, V> p);
    template <class T> void _print(vector <T> v);
    template <class T> void _print(set <T> v);
    template <class T, class V> void _print(map <T, V> v);
    template <class T> void _print(multiset <T> v);
    template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
    template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

    // ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

    const int MX = 2e5+123;
    vector<int> adj[MX];
    int parent[MX];
    int dis[MX];
    bool vis[MX];


    void bfs (int source)
    {
        queue<int> q;
        q.push (source);
        vis[source] = 1;
        dis[source] = 0;

        while (!q.empty())
        {
            int cur_v = q.front();
            q.pop();
            for (auto child : adj[cur_v])
            {
                if (vis[child]) continue;

                q.push (child);
                vis[child] = 1;
                parent[child] = cur_v;
                dis[child] = dis[cur_v] + 1;
            }
        }
    }


    int32_t main() {
    //#ifndef ONLINE_JUDGE
        //freopen("Error.txt", "w", stderr);
    //#endif

        fastio();

        int testcases = 1;
        //cin >> testcases;
        for (int tt = 1; tt <= testcases; tt++)
        {
            int n, m;
            cin >> n >> m;
            for (int i = 0; i < m; i++)
            {
                int a, b;
                cin >> a >> b;
                adj[a].push_back (b);
                adj[b].push_back (a);
            }

            bfs (1);

            if (!vis[n])
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }

            // for (int i = 1; i <= n; i++) cout << i << " " << parent[i] << endl;
            vector<int> ans (dis[n]+1);
            int u = n;
            for (int i = dis[n]; i >= 0; i--)
            {
                ans[i] = u;
                u = parent[u];
            }

            cout << ans.size() << endl;
            for (auto val : ans) cout << val << " ";
            cout << endl;
        }
        
        return 0;
    }
