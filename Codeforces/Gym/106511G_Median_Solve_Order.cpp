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
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) s.push_back (i+'A');

    int mid = (n - 1) / 2;
    string ans = "";
    ans += s[mid];
    // cout << ans << endl;

    if (n % 2 == 0)
    {
        for (int i = n-1; i >= 0; i--) 
        {
            if (i != (n-1)/2) ans += s[i];
        }
    }
    else 
    {
        if (mid - 1 >= 0) ans += s[mid - 1];

        for (int i = n - 1; i > mid; i--) ans += s[i];
        for (int i = mid - 2; i >= 0; i--) ans += s[i];

    }

    cout << ans << endl;
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