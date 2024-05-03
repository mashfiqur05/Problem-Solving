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

        vector<bool> is_prime(n+2, 1);

        is_prime[0] = is_prime[1] = 0;

        for (int i = 2; i * i <= n + 2; i++)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= n+2; j+=i)
                {
                    is_prime[j] = 0;
                }
            }
        }
        if (n < 3) cout << 1 << endl;
        else cout << 2 << endl;

        for (int i = 2; i <= n+1; i++)
        {
            if (is_prime[i] == 1) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
    }
    
    return 0;
}