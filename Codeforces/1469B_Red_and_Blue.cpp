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
        int n, m;
        cin >> n;
        vector<int> r(n+1);
        for (int i = 1; i <= n; i++) cin >> r[i];
        cin >> m;
        vector<int> b(m+1);
        for (int i = 1; i <= m; i++) cin >> b[i];
        
        vector<int> r_pre(n+1, 0), b_pre(m+1, 0);

        for (int i = 1; i <= n; i++) r_pre[i] = r_pre[i-1] + r[i];
        for (int i = 1; i <= m; i++) b_pre[i] = b_pre[i-1] + b[i];

        ll mx1 = *max_element (all (r_pre));
        ll mx2 = *max_element (all (b_pre));

        cout << mx1+mx2 << endl;
    }

    return 0;
}