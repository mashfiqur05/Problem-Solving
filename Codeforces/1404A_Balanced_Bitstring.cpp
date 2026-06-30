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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i + k < n; i++)
    {
        if (s[i] == s[i + k])
            continue;
        else if (s[i] != '?' && s[i + k] != '?' && s[i] != s[i + k])
        {
            cout << "NO" << endl;
            return;
        }
        else if (s[i] == '?')
        {
            s[i] = s[i + k];
        }
        else if (s[i + k] == '?')
        {
            s[i + k] = s[i];
        }
    }
    // cout << s << endl;

    int one = 0, zero = 0, question = 0;
    vector<int> pos;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '1')
            one++;
        else if (s[i] == '0')
            zero++;
        else
        {
            question++;
            pos.push_back(i);
        }
    }

    for (int i = 0; i + k < n; i++)
    {
        if (i != 0)
        {
            if (s[i+k-1] == '1') one++;
            else if (s[i+k-1] == '0') zero++;
            else question++;
        }
        // cout << i << ": " << one << " " << zero << " " << question << endl;
        if ((!question && one != zero) || one > k / 2 || zero > k / 2)
        {
            cout << "NO" << endl;
            return;
        }

        if (s[i] == '1') one--;
        else if (s[i] == '0') zero--;
        else question--;
    }

    if (k == n)
    {
        if ((!question && one != zero) || one > k / 2 || zero > k / 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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