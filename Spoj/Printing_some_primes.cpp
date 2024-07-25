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
        vector<bool> is_prime (1e8+1, true);

        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= 1e8+1; i++)
        {
            if (is_prime[i] && 1LL * i * i <= 1e8+1)
            {
                for (ll j = 2 * i; j <= 1e8+1; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        vector<int> prime_list;

        for (int i = 1; i < 1e8; i++)
        {
            if (is_prime[i])
                prime_list.push_back (i);
        }

        for (int i = 0; i <= prime_list.size(); i+=100)
        {
            cout << prime_list[i] << endl;
        }
    }
    
    return 0;
}