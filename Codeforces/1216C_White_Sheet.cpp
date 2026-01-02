///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))
#define unq(x)                                        \
    {                                                 \
        x.erase(unique(x.begin(), x.end()), x.end()); \
    }

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9 + 7;

void solve(int CaseNo)
{
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    bool f = false;
    x3 = max(x3, x1);
    y3 = max(y3, y1);
    x5 = max(x5, x1);
    y5 = max(y5, y1);
    x4 = min(x4, x2);
    y4 = min(y4, y2);
    x6 = min(x6, x2);
    y6 = min(y6, y2);

    int white = (x2 - x1) * (y2 - y1);

    int b1 = max(0LL, x4 - x3) * max(0LL, y4 - y3);
    int b2 = max(0LL, x6 - x5) * max(0LL, y6 - y5);

    int nx1 = max(x3, x5);
    int ny1 = max(y3, y5);
    int nx2 = min(x4, x6);
    int ny2 = min(y4, y6);

    int overlap = max(0LL, nx2 - nx1) * max(0LL, ny2 - ny1);

    int covered = b1 + b2 - overlap;

    if (covered >= white)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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