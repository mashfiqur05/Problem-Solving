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

int removeZeros(int num) {
    int ret = 0;
    int ten = 1;
    while (num) {
        int dig = num % 10;
        num /= 10;
        if (dig) {
            ret += dig * ten;
            ten *= 10;
        }
    }
    return ret;
}

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int a, b, c;
        cin >> a >> b;
        
        c = a + b;

        a = removeZeros(a);
        b = removeZeros(b);
        c = removeZeros(c);

        if (a + b == c) cout << "YES";
        else cout << "NO";
    }
    
    return 0;
}