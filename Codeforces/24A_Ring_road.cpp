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
const int MX = 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n;
map<pair<int, int>, int> cnt;
vector<int> undirect[MX];
bool vis[MX];
int cost1 = 0;

void dfs (int vertex)
{
    vis[vertex] = 1;

    for (int i = 0; i < undirect[vertex].size(); i++)
    {
        if (!vis[undirect[vertex][i]])
        {
            cost1 += cnt[{vertex, undirect[vertex][i]}];
            dfs (undirect[vertex][i]);
        }
    }
}

void solve (int testCase)
{
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        undirect[a].push_back (b);
        undirect[b].push_back (a);

        cnt[{a, b}] = c;
        cnt[{b, a}] = 0;
        total += c;
    }

    dfs (1);
    cost1 += cnt[{undirect[1][1], 1}];
    cout << min (cost1, total-cost1) << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}