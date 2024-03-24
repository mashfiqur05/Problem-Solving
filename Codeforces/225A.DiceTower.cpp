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

const ll MX = 123;
int arr[MX];
int brr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;
        
        ll x;
        cin >> x;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i] >> brr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if ((arr[i] == x) || (brr[i] == x) || (arr[i] == 7 - x) || (brr[i] == 7 - x))
            {
                return cout << "NO" << endl, 0;
            }
            //cout << arr[i] << ' ' << brr[i] << ' ';
            x = 7 - x;
            //cout << x << endl;
        }

        cout << "YES" << endl;
    }
    
    return 0;
}