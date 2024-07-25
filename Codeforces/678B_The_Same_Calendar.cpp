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

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];

bool leap(int z) 
{
	if (z % 4 == 0) 
    {
		if (z % 100 == 0) 
        {
			if (z % 400 == 0) return 1;
			else return 0;
		} 
        else return 1;
	} 
    else return 0;
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int year;
        cin >> year;

        int ans = year, tmp = 0;

        while (true)
        {
            tmp = (tmp + 365 + leap (ans)) % 7;

            if (tmp == 0 && (leap (year) == leap (ans+1))) return cout << ++ans << endl, 0;
            else ans++;
        }
    }
    
    return 0;
}