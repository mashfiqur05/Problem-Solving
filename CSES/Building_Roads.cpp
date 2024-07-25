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


void dfs (int vertex)
{
    vis[vertex] = 1;

    for (auto u : adj[vertex]) 
    {
        if (vis[u]) continue;

        dfs(u);
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

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0) 
            {
                dfs(i);
                ans.push_back (i);
            }
        }

        cout <<  ans.size()-1 << endl;
        for (int i = 0; i < ans.size()-1; i++)
        {
            cout << ans[i] << ' ' << ans[i+1] << endl;
        }
    }
    
    return 0;
}