#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int MX = 1e5+123;
vector<int> adj[MX];
bool vis[MX];
//int arr[MX];

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
        int n, e;
        int cnt = 0;
        cin >> n >> e;

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back (b);
            adj[b].push_back (a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                cnt++;
            }
            
        }

        cout << cnt << endl;
    }
    
    return 0;
}