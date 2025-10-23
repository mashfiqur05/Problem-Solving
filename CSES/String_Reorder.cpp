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

void solve(int CaseNo)
{
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'A']++;
    int n = s.size();

    int mx = *max_element(all(cnt));
    if (mx > (n + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }

    string ans;
    while ((int)ans.size() < n)
    {
        bool anything = false;

        pair<int, int> big = {0, 0};
        for (auto x : cnt)
        {
            if (x > big.first)
            {
                big.second = big.first;
                big.first = x;
            }
            else if (x > big.second)
            {
                big.second = x;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0 && (ans.size() == 0 || ans.back() != (char)(i + 'A')))
            {
                cnt[i]--;
                ans.push_back((char)(i + 'A'));
                int remain = n - ans.size();
                bool canFinish = true;

                if ((cnt[i]+1 == big.first ? big.second : big.first) > (remain + 1) / 2)
                    canFinish = false;
                // for (int j = 0; j < 26; j++)
                // {
                //     if (i != j)
                //     {
                //         if (cnt[j] > ((remain + 1) / 2))
                //         {
                //             canFinish = false;
                //             break;
                //         }
                //     }
                //     else
                //     {
                //         if (cnt[j] - 1 > remain / 2)
                //         {
                //             canFinish = false;
                //             break;
                //         }
                //     }
                // }

                if (!canFinish)
                {
                    cnt[i]++;
                    ans.pop_back();
                }
                else
                {
                    anything = true;
                    break;
                }
            }
        }

        if (!anything)
            break;
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve(tt);
    }

    return 0;
}