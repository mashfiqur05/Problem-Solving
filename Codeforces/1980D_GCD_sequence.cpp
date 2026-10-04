
///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()

const int N = 2e5 + 123;
const int MOD = 1e9 + 7;
const int inf = 2e18;


bool check(vector<int> &a, int remove)
{
    vector<int> b;

    for (int i = 0; i < sz(a); i++)
    {
        if (i == remove)
            continue;

        b.push_back(a[i]);
    }

    for (int i = 0; i + 2 < sz(b); i++)
    {
        int g1 = __gcd(b[i], b[i + 1]);
        int g2 = __gcd(b[i + 1], b[i + 2]);

        if (g1 > g2)
            return false;
    }

    return true;
}


void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;


    vector<int> g;

    for (int i = 0; i + 1 < n; i++)
    {
        g.push_back(__gcd(a[i], a[i + 1]));
    }

    int pos = -1;

    for (int i = 0; i + 1 < sz(g); i++)
    {
        if (g[i] > g[i + 1])
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "YES" << endl;
        return;
    }


    for (int remove = pos; remove <= pos + 2; remove++)
    {
        if (remove < n && check(a, remove))
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}


int32_t main()
{
    fastio();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int testcases;
    cin >> testcases;

    while (testcases--)
    {
        solve();
    }

    return 0;
}