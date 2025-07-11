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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1)
    {
        cout << l << endl;
        return;
    }

    /// even
    int right_bit;
    for (int i = 63; i >= 0; i--)
    {
        if ((1LL << i) & l)
        {
            right_bit = i;
            break;
        }
    }
    int val = 1LL << right_bit;
    val *= 2;
    // cout << right_bit << " " << val << endl;

    if (val > r || n == 2)
    {
        cout << -1 << endl;
        return;
    }

    if (k == n || k == n-1) cout << val << endl;
    else cout << l << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}