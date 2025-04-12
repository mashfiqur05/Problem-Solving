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

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }; 

void primeFactor (int n, map<int, int> &frq)
{
    // cout << n << endl;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            frq[i]++;
            n /= i;
            // cout << i << " ";
        }
    }
    if (n > 1) frq[n]++;
}

void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    map<int, int> frq;
    for (int i = 0; i < n; i++)
    {
        primeFactor (v[i], frq);
    }

    for (auto u : frq)
    {
        if (u.second % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}