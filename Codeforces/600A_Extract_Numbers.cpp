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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        int sz = s.size ();
        vector<string> v;
        string tmp = "";

        for (int i = 0; i < sz; i++)
        {
            if (s[i] == ';' || s[i] ==',')
            {
                v.push_back (tmp);
                tmp = "";
            }      
            else
            {
                tmp += s[i];
            } 
        }
        v.push_back (tmp);
        //cout << v.size () << endl;
        //for (auto u : v) cout << u << ',';
        vector<string> a, b;
        for (auto u : v)
        {
            bool f = 1;
            for (int i = 0; i < u.size(); i++)
            {
                if (u[0] == '0' && (u[1] >= '0' && u[1] <= '9'))
                {
                    f = 0;
                    break;
                }
                if ((u[i] >= 'A' && u[i] <= 'Z') || (u[i] >= 'a' && u[i] <= 'z') || u[i] == '.')
                {
                    f = 0;
                    break;
                }
            }

            if (u.size() == 0) a.push_back("");
            else if (f) b.push_back (u);
            else a.push_back (u);
            
        }
        if (b.size() == 0) cout << '-' << endl;
        else
        {   
            cout << "\"";
            for (int i = 0; i < b.size(); i++)
            {
                cout << b[i];
                if (i != b.size()-1) cout << ',';
            }
            cout << "\"" << endl;
        }
        if (a.size() == 0) cout << '-' << endl;
        else
        {
            cout << "\"";
            for (int i = 0; i < a.size(); i++)
            {
                cout << a[i];
                if (i != a.size()-1) cout << ',';
            }
            cout << "\"" << endl;
        }
        
    }
    
    return 0;
}   