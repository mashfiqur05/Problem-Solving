///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(3); cout.setf(ios::fixed,ios::floatfield);

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

int32_t main()
{
    fastio();
    fraction();

    double l, w, h, theta;
    while(cin >> l >> w >> h >> theta)
    {
        theta = theta * (PI / 180);
        double delta_h = l * tan(theta);
        double ans;

        if (delta_h <= h)
        {
            ans = l * w * (h - delta_h / 2.0);
        }
        else
        {
            double wet_len = h / tan(theta);
            ans = 0.5 * wet_len * h * w;
        }

        cout << ans << " mL" << endl;
    }

    return 0;
}