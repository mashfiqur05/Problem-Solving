///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
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
const int MOD = 1e9+7;

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1') x++; 
            }
            else
            {
                if (s[i] == '1') y++; 
            }
        }

        int x_shot = 0, y_shot = 0;
        for (int i = s.size(); i < 10; i++)
        {
            if (i & 1) y_shot++;
            else x_shot++;
        }
        int ans;

        if (s.size() % 2 == 0)
        {
            /// x is taking shot
            /// if both passed
            if (x + 1 <= y + y_shot && x + x_shot - 1 >= y) ans = -1;
            else if (x + 1 > y + y_shot) ans = 1;
            else ans = 0;
        }
        else
        {
            if (y + 1 <= x + x_shot && y + y_shot - 1 >= x) ans = -1;
            else if (y + 1 > x + x_shot) ans = 1;
            else ans = 0;
        }
        // cout << x << " " << y << " " << x_shot << " " << y_shot << endl;
        cout << ans << endl;
    }

    return 0;
}