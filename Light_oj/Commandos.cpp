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
vector<int> adj[N];
bool vis[N];
int level1[N];
int level2[N];


void bfs (int source, int *level)   
{
    queue<int> q;
    q.push (source);
    vis[source] = 1;

    while (!q.empty())
    {
        int cur_vartex = q.front();
        q.pop();

        for (auto child : adj[cur_vartex])
        {
            if (!vis[child])
            {
                q.push (child);
                vis[child] = 1;
                level[child] = level[cur_vartex] + 1;
            }
        }
    }
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {

        int n, r;
        cin >> n >> r;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
        }
        mem (level1, 0);
        mem (level2, 0);
        mem (vis, 0);

        for (int i = 0; i < r; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back (b);
            adj[b].push_back (a);
        }

        int s, d;
        cin >> s >> d;

        bfs (s, level1);
        mem (vis, 0);
        bfs (d, level2);
        mem (vis, 0);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max (ans, (level1[i] + level2[i]));
        }

        cout << "Case " << tt << ": " << ans << endl;
    }
    
    return 0;
}