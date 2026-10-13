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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> lmin(n), rmin(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)lmin[i] = v[i];
            else lmin[i] = min (v[i], lmin[i-1]);
        }
        for (int i = n-1; i >= 0; i--)
        {
            if (i == n-1) rmin[i] = v[i];
            else rmin[i] = min (v[i], rmin[i+1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int h = max (lmin[i], rmin[i]);
            if (h < v[i]) ans += (v[i]-h);
        }

        cout << ans << endl;
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