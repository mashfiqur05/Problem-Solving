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
        int n;
        cin >> n;

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

        int cnt = 0;
        
        for (int j = 1; j <= n; j++)
        {
            int prime_divisor = 0;
            for (int i = 1; i * i <= j; i++)
            {
                if (j % i == 0)
                {
                    if (is_prime[i]) prime_divisor++;
                    if (is_prime[j/i] && i != j/i) prime_divisor++;
                }
            }

            if (prime_divisor == 2) cnt++;
        }

        cout << cnt << endl;
    }
    
    return 0;
}