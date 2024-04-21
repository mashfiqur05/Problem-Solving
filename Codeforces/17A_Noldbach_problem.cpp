#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//int arr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, k;
        cin >> n >> k;

        vector<bool>is_prime(n+1, true);
        vector<int> all_primes;

        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (is_prime[i] && i * i <= n)
            {
                for (int j = i * i; j <= n; j+=i) 
                {
                    is_prime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i]) all_primes.push_back(i);
        }
        int cnt = 0;
        if (all_primes.size())
        {
            for (int i = 0; i < all_primes.size() - 1; i++)
            {
                int check = all_primes[i] + all_primes[i+1] + 1;
                if (check > n) break;
                if (is_prime[check]) cnt++;
            }
        }

        if (cnt >= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}