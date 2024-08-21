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

const int MX = 223;
char adj[MX][MX];
int vis[MX][MX];
int lev[MX][MX];
int n, m;
queue<pair<int, int>> q;

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid (int x, int y) 
{
    return x >= 0 && y >= 0 && x < n && y < m ;
}


int bfs()
{
    while (!q.empty())
    {
        auto point = q.front();
        q.pop();
        int cur_x = point.first, cur_y = point.second;
        // debug (point);
        for (auto move : movements)
        {
            int child_x = cur_x + move.first;
            int child_y = cur_y + move.second;
            // debug (child_x);
            // debug (child_y);

            if (vis[cur_x][cur_y] == 1)
            {
                if (!isValid (child_x, child_y))
                {
                    return lev[cur_x][cur_y] + 1;
                }
                else if (!vis[child_x][child_y] && adj[child_x][child_y] != '#' && isValid (child_x, child_y))
                {
                    vis[child_x][child_y] = 1;
                    lev[child_x][child_y] = lev[cur_x][cur_y] + 1;
                    q.push ({child_x, child_y});
                }
            }
            else 
            {
                if (isValid(child_x, child_y) && !vis[child_x][child_y] && adj[child_x][child_y] != '#')
                {
                    vis[child_x][child_y] = 2;
                    q.push ({child_x, child_y});
                }
            }
            
        }
    }

    return -1;
}

int32_t main() {
//#ifndef ONLINE_JUDGE
    //freopen("Error.txt", "w", stderr);
//#endif

    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        cin >> n >> m;
        pair<int, int> jane;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> adj[i][j];
                if (adj[i][j] == 'J') jane = {i, j};
                if (adj[i][j] == 'F') {q.push ({i, j}); vis[i][j] = 2;}
            }
        }

        q.push (jane);
        vis[jane.first][jane.second] = 1;

        int ans = bfs();

        if (ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;


        mem (vis, 0);
        mem (lev, 0);
        while (!q.empty()) q.pop();
    }
    
    return 0;
}
