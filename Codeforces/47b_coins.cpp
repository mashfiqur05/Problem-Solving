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
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        char ans1, ans2, ans3;

        if (s1[1] == '<') 
        {
            swap (s1[0], s1[2]);
        }
        if (s2[1] == '<') 
        {
            swap (s2[0], s2[2]);
        }
        if (s3[1] == '<') 
        {
            swap (s3[0], s3[2]);
        }

        if (s1[2] != s2[2] && s2[2] != s3[2] && s1[2] != s3[2]) 
        {
            cout << "Impossible";
            return 0;
        } 
        
        if (s1[0] != s2[0] && s2[0] != s3[0] && s1[0] != s3[0]) 
        {
            cout << "Impossible";
            return 0;
        } 
        
        if (s1[2] == s2[2]) ans1 = s1[2];
        if (s1[2] == s3[2]) ans1 = s1[2];
        if (s2[2] == s3[2]) ans1 = s2[2];

        if (s1[0] == s2[0]) ans3 = s1[0];
        if (s1[0] == s3[0]) ans3 = s1[0];
        if (s2[0] == s3[0]) ans3 = s2[0];

        if ((ans1 == 'A' || ans3 == 'A') && (ans1 == 'C' || ans3 == 'C')) ans2 = 'B';
        if ((ans1 == 'B' || ans3 == 'B') && (ans1 == 'C' || ans3 == 'C')) ans2 = 'A';
        if ((ans1 == 'B' || ans3 == 'B') && (ans1 == 'A' || ans3 == 'A')) ans2 = 'C';

        cout << ans1 << ans2 << ans3;
    }
    
    return 0;
}