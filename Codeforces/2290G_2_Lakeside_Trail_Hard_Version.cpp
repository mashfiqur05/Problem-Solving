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

bool isPossible (vector<int> &v, int k, int mid)
{
    int mx = max_element(v.begin(), v.end()) - v.begin();
    int n = v.size();
    vector<int> l(n), r(n);

    l[mx] = v[mx];
    r[mx] = v[mx];
    for (int i = 1; i < n; i++)
    {
        int lind = (mx+i) % n;
        int rind = (mx-i+n) % n;
        l[lind] = max (v[lind], l[(lind-1+n) % n] -mid);
        r[rind] = max (v[rind], r[(rind+1) % n] -mid);
    }

    int need = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = max (l[i], r[i]);
        need += (cur-v[i]);
    }

    return need <= k;
}


void solve ()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int l = 0, r = 1e9;
    int ans = r;
    while (l <= r)
    {
        int mid = l + (r-l)/2;

        if (isPossible (v, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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