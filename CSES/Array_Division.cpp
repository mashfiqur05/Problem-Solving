///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n, k;

bool isValid (vector<int> &v, ll max_sum)
{
    ll cnt = 0, cur_sum = 0;

    for (auto u : v)
    {
        if (u > max_sum) return false;

        if (u + cur_sum > max_sum)
        {
            cnt++;
            cur_sum = 0;
        }

        cur_sum += u;
    }

    if (cur_sum) cnt++;

    if (cnt > k) return false;
    else return true;
}


int32_t main()
{
    fastio();

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        ll r = accumulate (all (v), 0LL);
        ll l = *max_element (all (v));

        while (l < r)
        {
            ll mid = l + (r - l) / 2;

            if (isValid (v, mid))
            {
                r = mid;
            } 
            else l = mid + 1;
        }

        cout << l << endl;
    }

    return 0;
}