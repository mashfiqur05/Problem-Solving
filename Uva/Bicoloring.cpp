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

const int N = 212;
vector<int> adj[N];
int color[N];

bool bfs (int source)
{
    color[source] = 1;
    queue<int> q;
    q.push (source);

    while (!q.empty ())
    {
        int x = q.front();
        q.pop();

        int current_color;
        if (color[x] == 1) current_color = 2;
        else current_color = 1;

        for (auto u : adj[x])
        {
            if (color[u] == -1) 
            {
                color[u] = current_color;
                q.push(u);    
            }
            else if (color[u] == color[x]) 
                {
                    return false;
                }
        }
    }
    return true;
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {

        int n;
        while (cin >> n)
        {
            mem (color, -1);
        for (int i = 0; i <= N; i++)
        {
            adj[i].clear();
        }
            if (n == 0) break;
            int e;
            cin >> e;
            for (int i = 0; i < e; i++)
            {
                int a, b;
                cin >> a >> b;
                adj[a].push_back (b);
                adj[b].push_back (a);
            }

            bool f = bfs (0);
            // cout << f << endl;
            // for (int i = 0; i < n; i++)
            // {
            //     cout << color[i] << " ";
            // }

            if (f) cout << "BICOLORABLE." << endl;
            else cout << "NOT BICOLORABLE." << endl;
            
        }
    }
    
    return 0;
}