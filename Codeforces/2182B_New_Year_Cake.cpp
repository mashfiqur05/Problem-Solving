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
    int a, b; cin >> a >> b;
    if (a < b) swap (a, b);

    int k = 1, cur = 1, ans = 0, ai = a, bi = b;
    while (1)
    {
        if (cur == 1)
        {
            if (ai < k) break;
            ans++;
            ai -= k;
            k *= 2;
            cur = 2;
        }
        else 
        {
            if (bi < k) break;
            ans++;
            bi -= k;
            k *= 2;
            cur = 1;
        }
    }

    int cnt = 0;
    k = 1, cur = 2, ai = a, bi = b;
    while (1)
    {
        if (cur == 1)
        {
            if (ai < k) break;
            cnt++;
            ai -= k;
            k *= 2;
            cur = 2;
        }
        else 
        {
            if (bi < k) break;
            cnt++;
            cur = 1;
            bi -= k;
            k *= 2;
        }
    }

    // cout << ans << " " << cnt << endl;
    cout << max (ans, cnt) << endl;
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