///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9 + 7;

void solve(int testCase)
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (k >= 3)
    {
        cout << 0 << endl;
        return;
    }

    if (k == 1)
    {
        sort(all(v));
        ll ans = v[0];
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, v[i + 1] - v[i]);
        }

        cout << ans << endl;
    }
    else if (k == 2)
    {
        sort(all(v));
        ll ans = v[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                ll tmp = v[j] - v[i];
                ans = min (ans, tmp);
                ll pos = upper_bound (all (v), tmp) - v.begin();
                if (pos <= n)ans = min (ans, v[pos] - tmp);
                if (pos > 0) ans = min (ans, tmp - v[pos-1]); 
                // ans = min (ans, abs (tmp - v[pos]));
            }
        }

        cout << ans << endl;
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
        solve(tt);
    }

    return 0;
}