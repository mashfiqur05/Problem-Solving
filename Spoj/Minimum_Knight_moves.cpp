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

const int MX = 1e5+123;
bool vis[8][8];
int lev[8][8];

int get_x (string s)
{
    return s[0] - 'a';
}
int get_y (string s)
{
    return s[1] - '1';
}


bool isValid (int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8; 
}

vector<pair<int, int>> movements = { {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int bfs (string source, string dest)
{
    int sx = get_x (source);
    int sy = get_y (source);
    int dx = get_x (dest);
    int dy = get_y (dest);

    queue<pair<int, int>> q;
    q.push ({sx, sy});
    vis[sx][sy] = 1;
    lev[sx][sy] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for (auto move : movements)
        {
            int next_x = move.first + x;
            int next_y = move.second + y;

            if (!isValid (next_x, next_y)) continue;
            if (vis[next_x][next_y]) continue; 

            vis[next_x][next_y] = 1;
            q.push ({next_x, next_y});
            lev[next_x][next_y] = lev[x][y] + 1;
        }
    }

    return lev[dx][dy];
}


void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            lev[i][j] = 0;
            vis[i][j] = 0;
        }
    }
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
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        int ans = bfs (s1, s2);
        cout << ans << endl;        
    }
    
    return 0;
}
