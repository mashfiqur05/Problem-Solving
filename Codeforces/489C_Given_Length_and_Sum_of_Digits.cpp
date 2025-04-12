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
    /// -1 for only s = 0 or m * 9 < s cz s = 21 m = 2.
    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || m * 9 < s) 
    {
        cout << -1 << " " << -1 << endl;
        return;
    }

    string mx = "", mn = "";
    int tmp = s;
    while (tmp >= 9)
    {
        mx += '9';
        tmp -= 9;
    }
    if (tmp != 0) mx += (tmp + '0');
    for (int i = mx.size(); i < m; i++) mx += '0';
    // cout << mx << endl;

    /// for 1117999 m = 7, s = 38
    mn = mx;
    reverse(all(mn));
    int ind = 0;
    while (mn[ind] == '0' && ind < m-1)
        ind++;
    mn[ind]--;
    mn[0]++;

    cout << mn << " " << mx << endl;

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