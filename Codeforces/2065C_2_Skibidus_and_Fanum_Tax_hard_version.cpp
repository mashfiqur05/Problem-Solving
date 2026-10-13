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


void solve ()
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), na(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(all(b));
    for (int i = 0; i < n; i++)
    {
        int need = (i == 0 ? -infLL : na[i - 1]);

        int best = infLL;

        // Option 1: don't change
        if (a[i] >= need)
            best = min(best, a[i]);

        // Option 2: change
        auto it = lower_bound(all(b), need + a[i]);

        if (it != b.end())
            best = min(best, *it - a[i]);

        if (best == infLL)
        {
            cout << "NO\n";
            return;
        }

        na[i] = best;
    }

    // for (auto u : na) cout << u << " "; cout << endl;
    if (is_sorted(all (na))) cout << "YES" << endl;
    else cout << "NO" << endl;
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