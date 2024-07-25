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

int parent[123];
int sz[123];

int findParent (int u)
{
    if (u == parent[u]) return u;
    return parent[u] = findParent (parent[u]);
}

void make_union (int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int32_t main()
{
    Bismillah();

    int testcases;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";

        int n; 
        cin >> n;
        int u, v, w;
        vector<pair<int, pair<int, int>>> edge;
        
        while (cin >> u >> v >> w)
        {
            if (u == 0 && v == 0 && w == 0) break;
            edge.push_back({w, {u, v}});
        }   

        int mxST = 0, mnST = 0, cnt = 0;

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        sort(all(edge));

        for (auto e : edge)
        {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            u = findParent(u);
            v = findParent(v);

            if (u != v)
            {
                cnt++;
                mnST += w;
                make_union(u, v);
            }
            if (cnt == n) break;
        }

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        cnt = 0;
        sort(rall(edge));

        for (auto e : edge)
        {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            u = findParent(u);
            v = findParent(v);

            if (u != v)
            {
                cnt++;
                mxST += w;
                make_union(u, v);
            }
            if (cnt == n) break;
        }

        int sum = mxST + mnST;
        if (sum % 2 == 0) cout << sum / 2 << endl;
        else cout << sum << "/" << 2 << endl;
    }
    
    return 0;
}
