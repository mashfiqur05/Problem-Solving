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


void solve (int testCase)
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int ans = n;

    for (int i = 1; i <= n; i++)
    {
        bool f = 1;
        for (int j = i-1; j >= i-x && j >= 1; j--)
        {
            if (v[i] >= v[j])
            {
                f = 0;
                break;
            }
        }
        for (int j = i+1; j <= i+y && j <= n; j++)
        {
            if (v[i] >= v[j])
            {
                f = 0;
                break;
            }
        }

        if (f)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}