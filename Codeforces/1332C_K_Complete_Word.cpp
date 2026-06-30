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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < k / 2; i++)
    {
        map<char, int> mp;
        int cnt = 0;

        for (int j = i; j < n; j += k)
        {
            mp[s[j]]++;
            cnt++;
        }

        for (int j = k - 1 - i; j < n; j += k)
        {
            mp[s[j]]++;
            cnt++;
        }

        int mx = 0;

        for (auto [c, f] : mp)
            mx = max(mx, f);

        ans += cnt - mx;
    }

    if (k & 1)
    {
        int mid = k / 2;

        map<char, int> mp;
        int cnt = 0;

        for (int j = mid; j < n; j += k)
        {
            mp[s[j]]++;
            cnt++;
        }

        int mx = 0;

        for (auto [c, f] : mp)
            mx = max(mx, f);

        ans += cnt - mx;
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}