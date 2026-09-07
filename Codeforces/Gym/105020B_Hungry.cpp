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

/*
1 2 1 3 4 = 11

x, y, m
3 4 3

3+11= 14
4+4 = 8

5, 10, 2
5+11 = 16
3+

*/
void solve ()
{
    int n; cin >> n;
    vector<int> v(n), pref(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i == 0) pref[i] = v[i];
        else pref[i] = pref[i-1] + v[i];
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y, m; cin >> x >> y >> m;
        int t1 = max(x, pref[n-1]);
        int t2 = pref[m-1] + y;
        cout << min (t1, t2) << endl;
    }
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}