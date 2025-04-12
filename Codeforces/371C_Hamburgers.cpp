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
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void testCases (int tt)
{
    string a;
    cin >> a;
    ll b, s, c;
    cin >> b >> s >> c;
    ll pb, ps, pc, r;
    cin >> pb >> ps >> pc >> r;

    ll bread = 0, sausage = 0, capa = 0;
    for (auto u : a)
    {
        if (u == 'B') bread++;
        else if (u == 'S') sausage++;
        else if (u == 'C') capa++;
    }

    ll ans = 0;

    // cout << ans << " " << remain_tk << endl;
    ll from_poly = inf;
    if (bread != 0) from_poly = min (from_poly, (ll)b / bread);
    if (sausage != 0) from_poly = min (from_poly, (ll)s / sausage);
    if (capa != 0) from_poly = min (from_poly, (ll)c / capa);

    ans += from_poly;
    b -= (from_poly * bread);
    s -= (from_poly * sausage);
    c -= (from_poly * capa);
    // cout << ans << endl;
    // cout << b << " " << s << " " << c << endl;
    while (r)
    {
        bool f1 = 1, f2 = 1, f3 = 1;
        if (!bread || (bread && !b)) f1 = 0;
        if (!sausage || (sausage && !s)) f2 = 0;
        if (!capa || (capa && !c)) f3 = 0;

        if (!f1 && !f2 && !f3) break;

        ll need = 0;
        if (b < bread)
        {
            need += (bread - b) * pb;
            b = 0;
        }
        else b -= bread;
        if (s < sausage)
        {
            need += (sausage - s) * ps;
            s = 0;
        }
        else s -= sausage;
        if (c < capa)
        {
            need += (capa - c) * pc;
            c = 0;
        }
        else c -= capa;

        if (need > r) break;
        else 
        {
            r -= need;
            ans++;
        }
        // cout << "r " << r << " b " << b << " s " << s << " c " << c << " ans " << ans << endl;
    }

    ll cost = bread * pb + sausage * ps + capa * pc;
    ans += (r / cost);

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