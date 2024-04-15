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

const ll MX = 123;
char arr[MX][MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        char c;
        cin >> n >> m >> c;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        set<char> v;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == c)
                {
                    if (isupper (arr[i+1][j]) && arr[i+1][j] != c && i != n-1) v.insert (arr[i+1][j]);
                    if (isupper (arr[i][j+1]) && arr[i][j+1] != c && j != m-1) v.insert (arr[i][j+1]);
                    if (isupper (arr[i][j-1]) && arr[i][j-1] != c && j != 0) v.insert (arr[i][j-1]);
                    if (isupper (arr[i-1][j]) && arr[i-1][j] != c && i != 0) v.insert (arr[i-1][j]);
                }
            }
        }


        cout << v.size() << endl;
    }
    
    return 0;
}