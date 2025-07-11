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
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int CaseNo)
{
    int n, m; cin >> n >> m;
    if (n > m + 1 || m > 2 * n + 2)
    {
        cout << -1 << endl;
        return;
    }

    if (n >= m)
    {
        for (int i = 0; i < m; i++) cout << 0 << 1;
        if (n > m) cout << 0 << endl;
        else cout << endl;
    }
    else // m > n
    {
        if (m + 1 == n)
        {
            for (int i = 0; i < n; i++) cout << 1 << 0;
            cout << 1 << endl;
        }
        else if (m == 2 * n + 2)
        {
            for (int i = 0; i < n; i++) cout << 110;
            cout << 11 << endl;
        }
        else 
        {
            int multi = m - n - 1;
            for (int i = 0; i < multi; i++) cout << 110;
            for (int i = 2 * multi+1; i < m; i++) cout << 10;
            cout << 1 << endl;
        }
    }
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