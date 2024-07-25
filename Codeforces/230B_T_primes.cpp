#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const ll N = 10e12+123;

bool isPrime (ll n)
{
    int mx = sqrt(n);
    for (int i = 2; i <= mx; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

bool isPerfectSquare (ll n)
{
    ll tmp1 = sqrt (n);
    double tmp2 = sqrt (n);

    if (tmp1 == tmp2) return true;
    else return false;
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;

        if (n == 1) 
        {
            cout << "NO" << endl;
            continue;
        }
        if (isPerfectSquare (n) == 0) 
        {
            cout << "NO" << endl;
            continue; 
        }
        ll tmp = sqrt (n);
        if (isPrime(tmp)) cout << "YES" << endl;
        else cout << "NO" << endl;
        // cout << div << endl;
        // cout << isPerfectSquare (n) << endl;
    }
    
    return 0;
}