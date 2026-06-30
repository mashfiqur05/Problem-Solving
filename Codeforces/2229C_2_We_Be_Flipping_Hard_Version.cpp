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
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> prefix(n + 2, 0), suffix(n + 2, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + abs(v[i]);
    for (int i = n; i >= 1; i--)
        suffix[i] = suffix[i + 1] + v[i];

    int sum = suffix[1], last = -1;

    for (int i = 1; i <= n; i++)
    {
        if (v[i] > 0)
        {
            int s = prefix[i - 1] - v[i] + suffix[i + 1];
            if (s > sum)
            {
                sum = s;
                last = i;
            }
        }
    }

    if (last == -1)
    {
        cout << 0 << endl
             << endl;
        return;
    }

    vector<int> ans;
    int p = 0;
    for (int i = last - 1; i >= 1; i--)
    {
        int eff = (p % 2 == 0) ? v[i] : -v[i];
        if (eff > 0)
        {
            ans.push_back(i);
            p++;
        }
    }
    ans.push_back(last);

    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << " ";
    cout << endl;
}

int32_t main()
{
    fastio();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    //  srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve();
    }

    return 0;
}