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
char arr[4][4];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> arr[i][j];
            }
        }

        int same = 0;
        int notsame = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == arr[i][j+1]) same++;
                else notsame++;

                if (arr[i][j] == arr[i+1][j]) same++;
                else notsame++;

                if (arr[i][j] == arr[i+1][j+1])same++;
                else notsame++;

                if (same >= 2 || notsame == 3)
                {
                    cout << "YES";
                    return 0;
                }
                else
                {
                    same = 0;
                    notsame = 0;
                }
            }
        }

        cout << "NO";
    }
    
    return 0;
}