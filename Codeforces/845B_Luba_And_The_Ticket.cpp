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

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        vector<int> f, l;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 3; i++)
        {
            f.push_back (s[i]-'0');
            sum1 += s[i] - '0';
        }
        for (int i = 3; i < 6; i++)
        {
            l.push_back (s[i]-'0');
            sum2 += s[i] - '0';
        }

        if (sum1 == sum2) return cout << 0 << endl, 0;

        sort (all (f));
        sort (all (l));

        if (sum1 > sum2) 
        {
            swap (sum1, sum2);
            swap (f, l);
        } /// sum2 is always greater.
        
        // if (abs ((sum1-f[0]) - sum2) <= 9) cout << 1 << endl;
        // else if (abs ((sum2 - l[2]) - sum1) <= 9) cout << 1 << endl;
        // else cout << 2 << endl;

        if (((sum1 - f[0] + 9) >= sum2) || ((sum2 - l[2]) <= sum1)) cout << 1 << endl;
        else if (((sum1 - f[0] - f[1] + 18) >= sum2) || (sum2 - l[2] - l[1] <= sum1) || (sum1 -f[0] + 9 >= sum2 - l[2])) cout << 2 << endl;
        else cout << 3 << endl;
    }
    
    return 0;
}