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

    const double PI = acos(-1);
    const double eps = 1e-9;
    const int inf = 2000000000;
    const int MX = 2e5+123;
    const ll infLL = 9000000000000000000;
    #define MOD 1000000007

    ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
    ll n, v[MX];

    int32_t main()
    {
        fastio();

        int testcases = 1;
        cin >> testcases;
        for (int tt = 1; tt <= testcases; tt++)
        {
            cin >> n;
            for (int i = 0; i < n; i++) cin >> v[i];

            ll sum = 0, mn = 0;
            for (int i = 0; i < n; ++i) sum += v[i], mn = min(mn, sum);
            cout << sum - 2 * mn << endl;
        }

        return 0;
    }