#include<bits/stdc++.h>
using namespace std;

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

//const int MX = 123;
//int arr[MX];
int digitSum (int n)
{
    int ans = 0;
    while (n)
    {
        int digit = n % 10;
        n /= 10;
        ans += digit;
    }

    return ans;
}

int32_t main()
{
    Bismillah();

    vector<int> sum(2e5+123);
    vector<int> ans(2e5+123);

    for (int i = 1; i < 2e5+123; i++)
    {
        sum[i] = digitSum(i);
    }

    for (int i = 1; i < 2e5+123; i++)
    {
        ans[i] = ans[i-1] + sum[i];
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;

        cout << ans[n] << endl;
        
    }
    
    return 0;
}