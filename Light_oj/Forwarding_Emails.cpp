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

const int N = 50000+123;
vector<int> adj[N];
bool vis[N];
int dis[N];
int cnt = 0;

void dfs(int vertex)
{
    vis[vertex] = 1;
    
    for (auto child : adj[vertex])
    {
        if (vis[child] == 0)
        {
            cnt++;
            dfs (child);
        }
    }
    dis[vertex] = cnt;
    vis[vertex] = 0;
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
        mem (vis, 0);
        mem (dis, 0);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back (b);
        }

        int ans = INT_MIN;
        int id = 1;
        for (int i = 1; i <= n; i++)
        {
            cnt = 0;
            if (dis[i] == 0)dfs (i);
            if (cnt > ans)
            {
                ans = cnt;
                id = i;
            }
            
        }

        cout << "Case " << tt << ": " << id << endl;
    }
    
    return 0;
}