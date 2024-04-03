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

        char color[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

        int again = n / 7;

        while (again--)
        {
            for (int i = 0; i <= 6; i++)
            {
                cout << color[i];
            }
        }

        int rem = n % 7;

        if (rem == 1) cout << 'G';
        else if (rem == 2) cout << "GB";
        else if (rem == 3) cout << "YGB";
        else if (rem == 4) cout << "YGBI";
        else if (rem == 5) cout << "OYGBI";
        else if (rem == 6) cout << "OYGBIV";
    }
    
    return 0;
}