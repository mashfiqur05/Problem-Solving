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
    ll a, b; cin >> a >> b;
    if (b % 2 == 1)
    {
        if (a % 2 == 1) cout << a * b + 1 << endl;
        else cout << -1 << endl;
        return;
    }

    ll tmp = b, cnt = 0, k = 0;
    while (b % 2 == 0) 
    {
        b /= 2;
        cnt++;
    }

    if (a % 2 == 1 && cnt == 1)
    {
        cout << -1 << endl;
        return;
    }
    
    if (a % 2 == 1) k = 2;
    else k = 1;

    ll ans = a * k + tmp / k;
    ans = max (ans, a * (tmp / 2)+ 2);

    cout << ans << endl;
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