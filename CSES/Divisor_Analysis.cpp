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


int modPow(int a, int b, int mod) {
    int res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int modInv(int x) {
    return modPow(x, MOD - 2, MOD);
}



void solve ()
{
    int n; cin >> n;
    vector<pair<int, int>> factors(n);
    for (int i = 0; i < n; i++) cin >> factors[i].first >> factors[i].second;

    int number = 1, sum = 1, product = 1, cnt = 1; 
    for (auto u : factors)
    {
        int x = u.first, k = u.second;

        number *= (k+1);
        number %= MOD;

        int lob = (modPow(x, k + 1, MOD) - 1 + MOD) % MOD;
        int hor = modInv(x-1);
        sum *= (lob % MOD);
        sum %= MOD;
        sum *= (hor % MOD);
        sum %= MOD;

        // newProduct = oldProduct^(k + 1) * x^(oldDivisorCount * k * (k + 1) / 2)
        int exp = (k * (k + 1) / 2) % (MOD-1);
        product = modPow(product, k+1, MOD) * modPow(x, exp * cnt % (MOD-1), MOD);
        product %= MOD;
        cnt = cnt * ((k + 1) % (MOD-1)) % (MOD-1);
    }

    cout << number << " " << sum << " " << product << endl;
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}