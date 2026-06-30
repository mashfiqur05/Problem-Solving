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

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mod_mul(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 mod_pow(u64 base, u64 power, u64 mod) {
    u64 result = 1;

    while (power > 0) {
        if (power & 1) {
            result = mod_mul(result, base, mod);
        }

        base = mod_mul(base, base, mod);
        power >>= 1;
    }

    return result;
}

// O(log n) for fixed bases
bool isPrimeMillerRabin(u64 n) {
    if (n < 2) return false;

    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) {
            return n == p;
        }
    }

    u64 d = n - 1;
    int s = 0;

    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    vector<u64> bases = {
        2ULL, 325ULL, 9375ULL, 28178ULL,
        450775ULL, 9780504ULL, 1795265022ULL
    };

    for (u64 a : bases) {
        if (a % n == 0) continue;

        u64 x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1) continue;

        bool ok = false;

        for (int r = 1; r < s; r++) {
            x = mod_mul(x, x, n);

            if (x == n - 1) {
                ok = true;
                break;
            }
        }

        if (!ok) return false;
    }

    return true;
}

// Expected complexity: around O(n^(1/4))
u64 pollardRho(u64 n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;

    static mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );

    while (true) {
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
        u64 y = x;
        u64 d = 1;

        auto f = [&](u64 value) {
            return (mod_mul(value, value, n) + c) % n;
        };

        while (d == 1) {
            x = f(x);
            y = f(f(y));

            u64 diff;

            if (x > y) diff = x - y;
            else diff = y - x;

            d = __gcd(diff, n);
        }

        if (d != n) {
            return d;
        }
    }
}

void fastFactorize(u64 n, map<u64, int>& factors) {
    if (n == 1) return;

    if (isPrimeMillerRabin(n)) {
        factors[n]++;
        return;
    }

    u64 d = pollardRho(n);

    fastFactorize(d, factors);
    fastFactorize(n / d, factors);
}

// Print __uint128_t
void print_u128(u128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    string s;

    while (x > 0) {
        int digit = x % 10;
        s.push_back(char('0' + digit));
        x /= 10;
    }

    reverse(s.begin(), s.end());

    cout << s;
}

void solve ()
{
    int n; cin >> n;
    
    map<u64, int> factors;
    fastFactorize(n, factors);

    u128 ans = 1;
    for (auto u : factors)
    {
        u128 val = u.first, power = u.second, term = 1, curPower = 1;
        for (int i = 1; i <= power; i++)
        {
            curPower *= val; 
            term += curPower; 
        }

        ans *= term;
    }

    ans -= n;

    print_u128(ans);
    cout  << endl;
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