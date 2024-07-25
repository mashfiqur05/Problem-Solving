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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n, vector<int>(m));
        vector<vector<int>> brr(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char c;
                cin >> c;
                arr[i][j] = c - '0';
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char c;
                cin >> c;
                brr[i][j] = c - '0';
            }
        }

        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = m - 1; j >= 1; --j)
            {
                if (arr[i][j] != brr[i][j])
                {
                    int diff = (brr[i][j] - arr[i][j] + 3) % 3;
                    arr[i][j] = brr[i][j];
                    arr[i - 1][j] = (arr[i - 1][j] + 2 * diff) % 3;
                    arr[i][j - 1] = (arr[i][j - 1] + 2 * diff) % 3;
                    arr[i - 1][j - 1] = (arr[i - 1][j - 1] + diff) % 3;
                }
            }
        }


        bool f = 1;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i][0] != brr[i][0])
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            for (int j = 0; j < m; ++j)
            {
                if (arr[0][j] != brr[0][j])
                {
                    f = false;
                    break;
                }
            }
        }

        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}