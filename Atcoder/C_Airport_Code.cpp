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
        string s, t;
        cin >> s >> t;
        char a = tolower (t[0]);
        char b = tolower (t[1]);
        char c = tolower (t[2]);

        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == a)
            {
                int tmp = i;
                i = s.size();
                cnt++;
                //cout << cnt << endl;
                for (int j = tmp+1; j < s.size(); j++)
                {
                    if (s[j] == b)
                    {
                        int tp = j;
                        j = s.size();
                        cnt++;
                        //cout << cnt << endl;
                        for (int k = tp+1; k < s.size(); k++)
                        {
                            if(s[k] == c)
                            {
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        //cout << a << ' ' << b << ' ' << c << endl;
        //cout << cnt << endl;

        if (cnt == 2 && c == 'x') cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}