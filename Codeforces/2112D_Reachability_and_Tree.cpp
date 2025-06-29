///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int tt, int total)
{
    int n;
    cin >> n;
    vector<int> g[n+1], ans[n+1];
    vector<int> degree(n+1, 0), direction (n+1, -1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
        degree[u]++; degree[v]++;
    }

    int mainNode = -1;
    for (int i = 1; i <= n; i++) 
    {
        if (degree[i] == 2)
        {
            mainNode = i;
            break;
        }
    }

    if (mainNode == -1)
    {
        cout << "NO" << endl;
        return;
    }

    // cout << g[mainNode][0] << " " << g[mainNode][1] << endl;
    ans[mainNode].push_back (g[mainNode][0]);
    ans[g[mainNode][1]].push_back (mainNode);
    /// ingoing = 1, outgoing = 2;
    direction[mainNode] = 0; direction[g[mainNode][0]] = 1; direction[g[mainNode][1]] = 2;

    queue<int> q;
    q.push (g[mainNode][0]);
    q.push (g[mainNode][1]);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int dir = direction[cur];

        for (auto u : g[cur])
        {
            if (direction[u] == -1)
            {
                if (dir == 1)
                {
                    ans[u].push_back (cur);
                    direction[u] = 2;
                }
                else 
                {
                    ans[cur].push_back (u);
                    direction[u] = 1;
                }
                q.push (u);
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (auto u : ans[i]) cout << i << " " << u << endl;
    }

}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt, testcases);
    }

    return 0;
}