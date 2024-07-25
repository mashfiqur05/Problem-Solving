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

const int N = 30000+12;
vector<int> adj[N];
vector<int> cost[N];
bool vis[N];
int dis[N];

void bfs (int source)   
{
    queue<int> q;
    q.push (source);
    vis[source] = 1;

    while (!q.empty())
    {
        int cur_vartex = q.front();
        q.pop();

        int i = 0;
        for (auto child : adj[cur_vartex])
        {
            if (!vis[child])
            {
                q.push (child);
                vis[child] = 1;
                dis[child] = dis[cur_vartex] + cost[cur_vartex][i];
            }
            i++;
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
        cout << "Case " << tt << ": ";
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            cost[i].clear();
            vis[i] = 0;
            dis[i] = 0;
        }

        for (int i = 0; i < n-1; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back (b);
            adj[b].push_back (a);

            cost[a].push_back (c);
            cost[b].push_back (c);
        }

        bfs (0);
        int mx_distance = 0, node = 0;

        for (int i = 0; i < n; i++)
        {
            if (dis[i] > mx_distance)
            {
                mx_distance = dis[i];
                node = i;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            dis[i] = 0;
        }
        bfs (node);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (dis[i] > ans)
            {
                ans = dis[i];
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}