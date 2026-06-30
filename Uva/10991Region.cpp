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


void solve ()
{
    double r1, r2, r3; cin >> r1 >> r2 >> r3;

    double a = r1 + r2;
    double b = r2 + r3;
    double c = r1 + r3;

    double s = (a + b + c) / 2.0;
    double tri = sqrt(s * (s - a) * (s - b) * (s - c));

    double B = acos ((sq (a) + sq(c) - sq (b)) / (2 * a * c));
    double A = acos ((sq (b) + sq(c) - sq (a)) / (2 * b * c));
    double C = acos ((sq (a) + sq(b) - sq (c)) / (2 * a * b));

    double rmv = .5 * ((r1*r1*B) + (r2*r2*C) + (r3*r3*A));

    double shaded = tri - rmv;

    cout << fixed << setprecision(6) << shaded << endl;
}


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}