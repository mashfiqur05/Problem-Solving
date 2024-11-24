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


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        map<pair<pair<int, int>, int>, int> freq;

        ll res = 0;
        for (int i = n - 2; i >= 1; i--)
        {
            ll a = v[i], b = v[i + 1], c = v[i + 2];
            res += freq[{{a, b}, 0}] - freq[{{a, b}, c}];
            res += freq[{{a, 0}, c}] - freq[{{a, b}, c}];
            res += freq[{{0, b}, c}] - freq[{{a, b}, c}];

            freq[{{a, b}, 0}]++;
            freq[{{a, 0}, c}]++;
            freq[{{0, b}, c}]++;
            freq[{{a, b}, c}]++;
        }
        cout << res << endl;
    }

    return 0;
}