#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//vector<ll> arr(MX);


bool isPrime (int a)
{
    bool ans = 1;
    for (int i = 2; i <= sqrt (a); i++)
    {
        if (a % i == 0)
        {
            ans = 0;
            break;
        }
    }

    return ans;
}

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n, m;
        cin >> n >> m;

        for (int i = n+1; i <= m; i++)
        {
            bool res = isPrime(i);
            if (res == 1)
            {
                if (i == m)
                {
                    return cout << "YES" << endl, 0;
                }
                else 
                {
                    return cout << "NO" << endl, 0;
                }
            }
        }

        cout << "NO" << endl;
    }
    
    return 0;
}