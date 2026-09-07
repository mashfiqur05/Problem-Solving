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

/*
xi = xj 

(1 0), (2, 1), (3, 0)
*/
void solve ()
{
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    sort (all (v));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first, y = v[i].second;
        if (i+1 < n && v[i].first == v[i + 1].first)
        {
            ans += (n - 2);
        }
        if (y == 1 && binary_search(all(v), make_pair(x+1, 0LL)) && binary_search(all(v), make_pair(x-1, 0LL))) ans++;
        if (y == 0 && binary_search(all(v), make_pair(x+1, 1LL)) && binary_search(all(v), make_pair(x-1, 1LL))) ans++;
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