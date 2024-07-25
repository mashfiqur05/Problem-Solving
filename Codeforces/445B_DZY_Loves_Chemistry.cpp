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

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int N = 123;
bool vis[N];
vector<int> adj[N];

void dfs (int vertex)
{
    vis[vertex] = 1;

    for (auto child : adj[vertex])
    {
        if (vis[child]) continue;

        dfs (child);
    }
}


int32_t main()
{
    Bismillah();

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

        int cnt = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                cnt++;
            }
        }
        
        ll ans = pow (2, (n - cnt));
        cout << ans << endl;
    }
    
    return 0;
}