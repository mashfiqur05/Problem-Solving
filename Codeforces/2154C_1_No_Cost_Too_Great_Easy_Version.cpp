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

int spf[MX];

void sieve()
{
    for (int i = 2; i < MX; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            if (i * i < MX)
            {
                for (int j = i * i; j < MX; j += i)
                {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }
}

vector<int> getPrimeFactors(int x)
{
    vector<int> primes;
    if (x <= 1) return primes;
    while (x > 1)
    {
        int p = spf[x];
        primes.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    return primes;
}

void solve(int CaseNo)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int, int> best;
    int ans = 2;

    for (int i = 0; i < n; i++)
    {
        for (int add = 0; add <= 900; add++)
        {
            int val = a[i] + add, cost = add * b[i];
            for (int p : getPrimeFactors(val))
            {
                if (best.count(p))
                {
                    ans = min(ans, cost + best[p]);
                    best[p] = min(best[p], cost);
                }
                else best[p] = cost;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));
    sieve();
    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}