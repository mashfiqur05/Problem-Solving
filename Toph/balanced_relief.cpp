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
const int MOD = 1e9+7;


void testCases (int tt)
{
    int n, m, l, r;
    cin >> n >> m;
    vector<int> male(n), female(m);
    for (int i = 0; i < n; i++) cin >> male[i];
    for (int i = 0; i < m; i++) cin >> female[i];
    cin >> l >> r;

    sort (all (male));
    sort (all (female));

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int st = l - male[i], end = r - male[i];
        int x1 = lower_bound (all (female), st) - female.begin();
        int x2 = upper_bound (all (female), end) - female.begin();

        ans += (x2 - x1);
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
        testCases (tt);
    }

    return 0;
}