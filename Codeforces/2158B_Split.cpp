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
9 9 9 7 7 7 9 7 7 7 
7 - 6
9 - 4

1 1 1 2 4 4 4 4 5 5
{2, 4, 4, 4, 5} {1, 1, 1, 4, 5}
1 - 3
2 - 1
4 - 4
5 - 2


1 2 1 2 1 2 1 2
1 - 4
2 - 4
3 - 4
{1, 2, 2, 2} {1, 1, 1, 2}


1 2 3 4 5 4 1 4 1 5 4 6
1 - 3
2 - 1
3 - 1
4 - 4
5 - 2
6 - 1
*/
void solve ()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];

    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        mp[a[i]]++;
    }
    int odd = 0, even = 0;

    for (auto [x, c] : mp)
    {
        if (c & 1)
            odd++;
        else
            even++;
    }

    int ans = 0;

    if (odd > 0)
    {
        ans = odd + 2 * even;
    }
    else
    {
        ans = 2 * even;

        if ((n % 2) != (even % 2))
            ans -= 2;
    }
    cout << ans << endl;
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
        solve ();
    }

    return 0;
}