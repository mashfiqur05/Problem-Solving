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

bool cmp (pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve ()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;

        int withOutGem = 0, mxgem = 0, getExtra = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
            if (v[i].second == 0)
                withOutGem++;
            if (v[i].second > 1)
                getExtra += (v[i].second - 1);
            mxgem += v[i].second;
        }

        sort(all(v), cmp);
        // for (auto u : v) cout << u.first << " " << u.second << endl;
        // cout << withOutGem << endl;

        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second)
            {
                ind = i;
                break;
            }
        }

        int ans = 0;
        if (ind == -1)
        {
            // no gems anywhere: must pay for all
            for (int i = 0; i < n; i++)
                ans += v[i].first;
        }
        else
        {
            ans = v[ind].first;
            int cnt = 1;          // bottles paid with coins
            int need = n - mxgem; // minimum number that must be paid with coins

            for (int i = 0; i < n; i++)
            {
                if (cnt >= need)
                    break; // check BEFORE adding
                if (i == ind)
                    continue;
                ans += v[i].first;
                cnt++;
            }
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