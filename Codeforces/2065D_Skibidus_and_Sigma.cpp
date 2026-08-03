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
/*3 4
2 2 2 2
3 2 1 2
4 1 2 1

4121 -> 48 + 11 + 20 + 9 = 88
3212 -> 36 + 22 + 10 + 18 = 86
2222 -> 24 + 22 + 20 + 18 = 84
*/

void solve ()
{
    int n, m; cin >> n >> m;
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> cur(m);
        for (int j = 0; j < m; j++) cin >> cur[j];
        // sort (rall (cur));
        int sum = accumulate (all (cur), 0LL);
        v.push_back ({sum, cur});
    }

    sort (rall (v));

    int ans = 0, mul = n*m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += (v[i].second[j] * mul);
            // cout << ans << " " << mul << " " << v[i].second[j] << endl;
            mul--;
        }
        // cout << endl;
    }

    cout << ans << endl;
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}