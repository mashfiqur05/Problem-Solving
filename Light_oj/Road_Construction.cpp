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

const int N = 55;
int parent[N];
int sz[N];

int find_parent (int u)
{
    if (u == parent[u]) return u;
    else return parent[u] = find_parent (parent[u]);
}

void make_parent (int u, int v)
{
    u = find_parent (u);
    v = find_parent (v);
    if (u != v)
    {
        if (sz[u] < sz[v]) swap (u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int m;
        cin >> m;
        vector<pair<int, pair<string, string>>> StEdge;
        set<string> s;
        mem (parent, 0);
        mem (sz, 0);
        s.clear();
        
        for (int i = 0; i < m; i++)
        {
            int w;
            string u, v;
            cin >> u >> v >> w;
            StEdge.push_back ({w, {u, v}});
            s.insert (u);
            s.insert (v);
        }        

        int n = s.size();
        map<string, int> mp;

        int id = 1;
        for (auto u : s)
        {
            mp[u] = id;
            id++;
        }

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }

        vector<pair<int, pair<int, int>>> edges;
        for (auto e : StEdge)
        {
            string u = e.second.first;
            string v = e.second.second;
            int w = e.first;

            edges.push_back ({w, {mp[u], mp[v]}});
        }        
        sort (all (edges));

        int mnSt = 0, cnt = 0;

        for (auto e : edges)
        {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            u = find_parent (u);
            v = find_parent (v);

            if (u != v)
            {
                make_parent (u, v);
                mnSt += w;
                cnt++;
            }
            if (cnt == n-1) break;
        }

        cout << "Case " << tt << ": ";
        if (cnt < n-1) cout << "Impossible" << endl;
        else cout << mnSt << endl;
    }
    
    return 0;
}