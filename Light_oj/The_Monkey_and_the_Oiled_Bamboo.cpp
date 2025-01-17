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


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> diff (n);
        diff[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            diff[i] = abs (v[i] - v[i-1]);
        }

        sort (all (diff));
        int ans = diff[n-1];
        int prev = diff[n-1];
        bool f = 0;

        for (int i = n-2; i >= 0; i--)
        {
            if (prev == diff[i])
            {
                prev--;
            }
            if (prev < diff[i])
            {
                f = 1;
                break;
            }
        }

        if (f) cout << ans + 1 << endl;
        else cout << ans << endl;
    }

    return 0;
}