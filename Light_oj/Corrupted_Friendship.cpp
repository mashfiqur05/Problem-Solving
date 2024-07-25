#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int N = 1e5+123;
vector<int> adj[N];
bool vis[N];
ll ans = 0, cnt = 0, n;

void dfs (int vertex)
{
    vis[vertex] = 1;
    cnt++;

    for (auto u : adj[vertex])
    {
        if (vis[u] == 0)
        {
            dfs (u);
        }
        ans += (n - cnt);
    }
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> n;
        for (int i = 0; i < n-1; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back (b);
        }

        for (int i = 1; i <= n; i++) 
        {
            if (vis[i] == 0) dfs (i);
        }

        cout << "Case " << tt << ": " << (n - 1) << " " << ans << endl;

        ans = 0, cnt = 0;
        for (int i = 0; i <= n; i++) adj[i].clear();
        mem (vis, 0);
    }
    
    return 0;
}