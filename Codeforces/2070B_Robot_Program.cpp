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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    ll first_zero = -1, full_cycle = -1, pos = x;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L') pos--;
        else pos++;

        if (pos == 0)
        {
            first_zero = i+1;
            break;
        }
    }

    if (first_zero == -1)
    {
        cout << 0 << endl;
        return;
    }
    else 
    {
        pos = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L') pos--;
            else pos++;

            if (pos == 0)
            {
                full_cycle = i+1;
                break;
            }
        }

        k -= first_zero;
        ll ans;
        if (full_cycle != -1) ans = k / full_cycle;
        else ans = 0;
        cout << ans + 1 << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}