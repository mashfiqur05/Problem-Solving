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
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n), need;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int a_win = 0, required = n / 2 + 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i]) a_win++;
            else 
            {
                need.push_back (b[i] - a[i] + 1);
            }
        }

        sort (all (need));

        for (auto u : need)
        {
            if (a_win >= required) break;

            if (x >= u) 
            {
                x -= u;
                a_win++;
            }
            else break;
        }

        if (a_win >= required) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}