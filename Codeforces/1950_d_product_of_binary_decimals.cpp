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


bool isDecimalBinary (int a)
{
    while (a)
    {
        int digit = a % 10;
        if (digit != 0 && digit != 1)
        {
            return false;
        }  
        a /= 10; 
    }

    return true;
}


int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;

        int check[] = {10, 11, 101, 111};
        bool flag = 0;

        for (int i = 0; i < 4;)
        {
            if (isDecimalBinary (n))
            {
                flag = 1;
                break;
            }

            if ((n % check[i]) == 0)
            {
                n = n / check[i];
                i = 0;
            }
            else
            {
                i++;
            }
        }

        if (flag == 1) 
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}