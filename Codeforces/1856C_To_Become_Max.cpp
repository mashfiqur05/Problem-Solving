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

bool isPossible (vector<int> &v, int target, int k)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int nk = 0, cur = target;
        for (int j = i; j < n; j++)
        {
            if (cur <= v[j]) break;
            nk += max (0LL, cur - v[j]);
            // cout << cur << " " << v[j] << " " << nk << endl;
            cur--;
            if (j == n-1)
            {
                nk += inf;
            }
        }

        // cout << target << " " << nk << " " << k << " " << cur << " " << v[n-1]<< endl;
        if (nk <= k) return true;
    }

    return false;
}


void solve ()
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = *max_element(all (v));
    int l = ans, r = 1e9;

    while (l <= r)
    {
        int mid = (l+r)/2;

        if (isPossible (v, mid, k))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
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