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

const ll MX = 523;
char arr[MX][MX];

//// just have to check only outer rectangle

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;
        int cntw = 0, cntb = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] == 'W') 
            {
                cntw++;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i][m-1] == 'W') 
            {
                cntw++;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i][0] == 'B') 
            {
                cntb++;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i][m-1] == 'B') 
            {
                cntb++;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (arr[0][i] == 'W')
            {
                cntw++;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (arr[n-1][i] == 'W')
            {
                cntw++;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (arr[0][i] == 'B')
            {
                cntb++;
                break;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (arr[n-1][i] == 'B')
            {
                cntb++;
                break;
            }
        }

        //cout << cntb << ' ' << cntw << endl;
        if (cntb == 4 || cntw == 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}