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

const int MX = 1123;
char adj[MX][MX];
bool vis[MX][MX];
int n, m;

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid (int x, int y) 
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs (int i, int j)
{
    queue<pair<int, int>> q;
    q.push ({i, j});
    vis[i][j] = 1;
    
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x_cur = p.first;
        int y_cur = p.second;

        for (auto move : movements)
        {
            int xchild = x_cur + move.first;    
            int ychild = y_cur + move.second;

            if (vis[xchild][ychild] || adj[xchild][ychild] == '#') continue;
            if (!isValid(xchild, ychild)) continue;

            q.push ({xchild, ychild});
            vis[xchild][ychild] = 1;
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
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> adj[i][j];
            }
        }   

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (adj[i][j] != '#' && !vis[i][j])
                {
                    bfs (i, j);
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
