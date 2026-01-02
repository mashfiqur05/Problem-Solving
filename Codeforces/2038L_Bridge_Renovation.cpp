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
    int n; cin >> n;
    int p18 = n, p21 = n, p25 = n;
    int ans = 0;

    while (p18 || p21 || p25)
    {
        if (p21 >= 2)
        {
            p21 -= 2;
            p18--;
        }
        else if (p21 == 1 && p18 >= 2)
        {
            p18 -= 2;
            p21--;
        }
        else if (p21 == 1)
        {
            p21--;
            p25--;
        }
        else if (p18 >= 3)
        {
            p18 -= 3;
        }
        else 
        {
            ans += ((p25 + p21 + p18 + 1) / 2);
            break;
        }
        ans++;
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