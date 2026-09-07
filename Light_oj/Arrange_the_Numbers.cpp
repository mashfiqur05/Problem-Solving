#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;
const int N = 1005;

ll fact[N], invFact[N];

ll modPow(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

ll nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}

void precompute()
{
    fact[0] = 1;

    for (int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % MOD;

    // inverse of fact[N-1]
    invFact[N-1] = modPow(fact[N-1], MOD - 2);

    for (int i = N-2; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    ll firstChoose = nCr(m, k);

    ll ans = 0;

    // Inclusion-Exclusion
    for (int i = 0; i <= m-k; i++)
    {
        ll bad = nCr(m-k, i) * fact[n-k-i] % MOD;

        if (i & 1)
            ans = (ans - bad + MOD) % MOD;
        else
            ans = (ans + bad) % MOD;
    }

    ans = ans * firstChoose % MOD;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}