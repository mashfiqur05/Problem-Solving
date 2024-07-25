#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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

const ll N = 2e5+123;
vector<ll> adj[N];
bool vis[N];
vector<ll> dis(N, 1);

void dfs (int vertex)
{
    vis[vertex] = 1;

    for (auto u : adj[vertex])
    {
        if(vis[u]) continue;

        dfs(u);
        dis[vertex] += dis[u];
    }
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;
        for (int i = 2; i <= n; i++)
        {
            int a;
            cin >> a;
            adj[a].push_back (i);
            adj[i].push_back (a);
        }

        dfs(1);

        for (int i = 1; i <= n; i++)
        {
            cout << dis[i]-1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}