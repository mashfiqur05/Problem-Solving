///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(4);           \
    cout.setf(ios::fixed, ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))
#define unq(x)                                        \
    {                                                 \
        x.erase(unique(x.begin(), x.end()), x.end()); \
    }

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    while (cin >> n >> m)
    {
        double before = 10000.0 / (1.0 * n);
        double after = 10000.0 / (1.0 * (n + m));

        double ans = 0, nxt = 0.0;
        for (int i = 0; i < n + m; i++)
        {
            double cur = after * i;
            if (cur == nxt)
                nxt += before;
            else if (cur > nxt)
            {
                double prev = cur - after;
                if (nxt - prev >= cur - nxt)
                {
                    ans += (cur - nxt);
                    nxt += before;
                }
                else
                {
                    ans += (nxt - prev);
                    nxt += before;
                }
            }
        }

        cout << ans << endl;
    }
}

int32_t main()
{
    fraction();
    fastio();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //  srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve();
    }

    return 0;
}