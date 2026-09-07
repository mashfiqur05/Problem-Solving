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

/*
5, 10, 15, 20, 
25 = 5*5
5*5*5 = 125
125*5 = 625

5, 125, 625, ...
*/

/*
impossible case
15!= 5, 10, 15 = 1, 1, 1
25! = 1, 1, 1, 1, 2
125 = 1, 1, 1, 1, 2, 1, 1, 1, ..., 2 = 125/5 + 2 = 27 
*/

int isPossible (int n)
{
    int cnt = 0;
    for (int i = 5; i <= n; i*=5)
    {
        cnt += (n / i);
    }

    return cnt;
}

void solve ()
{
    int n; cin >> n;

    int l = 1, r = LLONG_MAX, ans = -1;
    while (l <= r)
    {
        int mid = l + (r-l)/2;

        if (isPossible (mid) == n)
        {
            ans = mid;
            r = mid -1;
        }
        else if (isPossible (mid) > n) r = mid - 1;
        else l = mid + 1;
    }

    if (ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
}


int32_t main()
{
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
        cout << "Case " << tt << ": ";
        solve ();
    }

    return 0;
}