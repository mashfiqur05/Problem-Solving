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

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        int sz = s.size();

        for (int i = 0; i < sz; i++)
        {
            if (s[i] == s[i+1])
            {
                char ch = s[i+1];
                for (int j = 1;; j++)
                {if ((ch+j) != s[i+2] && islower(ch+j)) 
                {
                    ch += j;
                    // cout << "ch " << ch << endl;
                    break;
                }
                else if ((ch-j) != s[i+2] && islower (ch-j))
                {
                    ch -= j;
                    // cout << "ch = " << ch << endl;
                    break;
                }}
                s[i+1] = ch;
            }
        }

        cout << s << endl;
    }
    
    return 0;
}