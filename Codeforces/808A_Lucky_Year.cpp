#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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
        string s1;
        cin >> s1;
        int sz = s1.size();
        int n1 = stoi (s1);
        if (s1[0] == '9')
        {
            sz++;
            s1[0] = '1';
        }
        else s1[0]++;
        for (int i = 1; i < sz; i++) s1[i] = '0';
        int n2 = stoi (s1);
        int ans = (n2 - n1);
        cout << ans << endl;
    }
    
    return 0;
}