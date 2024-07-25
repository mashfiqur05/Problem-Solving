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

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        stack<char> st;

        int n = s.size();
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push (s[i]);
            else
            {
                if (!st.empty())
                {
                    char ch = st.top();

                    if ((s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '['))
                    {
                        st.pop();
                    }
                    else
                    {
                        f = 0;
                    }
                }
                else 
                {
                    f = 0;
                }
            }
        }

        if (st.empty() && f == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}