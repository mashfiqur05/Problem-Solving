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

//const int N = 1e5+123;
//int arr[N];

map<string, vector<string>> adj;
map<string, int> level;
map< string, string> parent;

void bfs (string source)
{
    queue<string> q;
    q.push (source);

    level[source] = 1;

    while (!q.empty())
    {
        string x = q.front();
        q.pop();
        
        for (auto u : adj[x])
        {
            if (level[u] == 0)
            {
                level[u] = level[x] + 1;
                parent[u] = x;
                q.push (u);
            }
        }
    }
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n; 
        bool f = 0;
        while (cin >> n)
        {
            if (f) cout << endl;
            f = 1;
        
        adj.clear();
        level.clear();
        parent.clear();

        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            adj[a].push_back (b);
            adj[b].push_back (a);
        }

        string s, d;
        cin >> s >> d;
        bfs (s);
        
        if (level[d] == 0)
        {
            cout << "No route" << endl;
            continue;
        }
        vector<pair<string, string>> ans;

        while (!parent[d].empty())
        {
            ans.push_back ({parent[d], d});
            d = parent[d];
        }

        reverse (all (ans));

        for (auto u : ans)
        {
            cout << u.first << " " << u.second << endl;
        }
        }
    }
    
    return 0;
}