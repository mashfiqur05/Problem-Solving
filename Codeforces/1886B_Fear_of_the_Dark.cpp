///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

double dist(int x1, int y1, int x2, int y2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;

    return sqrt(1.0 * dx * dx + 1.0 * dy * dy);
}



void solve ()
{
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    double OA = dist(0, 0, ax, ay);
    double OB = dist(0, 0, bx, by);
    double AP = dist(ax, ay, px, py);
    double BP = dist(bx, by, px, py);
    double AB = dist(ax, ay, bx, by);

    double ans = DBL_MAX;

    ans = min(ans, max(OA, AP));
    ans = min(ans, max(OB, BP));
    ans = min(ans, max({AB / 2.0, OA, BP}));
    ans = min(ans, max({AB / 2.0, OB, AP}));

    cout << ans << endl;
}

int32_t main()
{
    fraction();
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}