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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 1123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> g[MX];
int money[MX];
bool vis[MX];
int cur_cost = 0, node = 0;

void dfs (int vertex)
{
    vis[vertex] = 1;
    cur_cost += money[vertex];
    node++;

    for (auto child : g[vertex])
    {
        if (!vis[child])
        {
            dfs (child);
        }
    }
}

void solve (int testCase)
{
    mem (vis, 0);
    cur_cost = 0;
    node = 0;
    cout << "Case " << testCase << ": ";
    int n, m;
    cin >> n >> m;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> money[i];
        total += money[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }

    if (total % n != 0)
    {
        cout << "No" << endl;
        return;
    }

    int avg = total / n;
    bool f = 1;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs (i);
            if (cur_cost / node != avg)
            {
                f = 0;
                break;
            }
            cur_cost = 0;
            node = 0;
        }
    }

    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;

    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
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
        solve (tt);
    }

    return 0;
}