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
string decToBinary(int n)
{
    string ans = "";
    for (int i = 7; i >= 0; i--) 
    {
        int k = n >> i;
        if (k & 1)
            ans += '1';
        else
            ans += '0';
    }

    return ans;
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        string dec, bin;
        cin >> dec >> bin;
        vector<string> v;
        vector<string> s;
        string tmp = "";
        for (int i = 0; i < dec.size(); i++)
        {
            if (dec[i] == '.')
            {
                v.push_back (tmp);
                tmp = "";
            }
            else tmp += dec[i];
        }
        v.push_back (tmp);
        
        tmp = "";
        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i] == '.')
            {
                s.push_back (tmp);
                tmp = "";
            }
            else tmp += bin[i];
        }
        s.push_back (tmp);

        for (int i = 0; i < 4; i++)
        {
            string a = v[i];
            int x;
            if (!a.empty()) x = stoi (a);
            v[i] = decToBinary (x);
        }

        if (v[0] == s[0] && v[1] == s[1] && v[2] == s[2] && v[3] == s[3]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}