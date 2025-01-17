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
const int MX = 3e5+123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }


vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true); // Initialize all numbers as prime
    vector<int> primes; // Vector to store prime numbers

    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            // Marking multiples of p as not prime
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Collecting all prime numbers
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes; // Return the list of prime numbers
}


int32_t main()
{
    fastio();

    vector<int> primes = sieve(1e7);

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;

        int id = 0;
        for (int i = 0; i < n; i++)
        {
            id = i;
            for (int j = 0; j < m; j++)
            {
                cout << primes[id] << " ";
                id++;
            }
            cout << endl;
        }
    }

    return 0;
}