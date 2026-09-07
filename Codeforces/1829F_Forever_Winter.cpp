///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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


void solve ()
{
    int n, m; cin >> n >> m;
    map<int, int> degree;
    for (int i = 0; i < m; i++) 
    {
        int u, v; cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    map<int, int> cnt;
    for (auto u : degree) cnt[u.second]++;

    // cout << cnt.size() << endl;
    // for (auto u : cnt) cout << u.first << " " << u.second << endl;
    int x, y;
    if (cnt.size() == 2)
    {
        for (auto u: cnt)
        {
            x = u.first;
            y = u.first-1;
        }
    }
    else 
    {
        for (auto u : cnt)
        {
            if (u.second == 1) x = u.first;
            else y = u.first-1;
        }
    }

    cout <<  x << " " << y << endl;
}




int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}