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

// const int N = 1e5+123;
// char arr[N][N];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;
        vector<string> arr(n);

        for (int i = 0; i < n; i++) cin >> arr[i];

        ll sumx = 0, sumy = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                {
                    sumx += i+1;
                    sumy += j+1;
                    cnt++;
                }
            }
        }

        int x = sumx / cnt;
        int y = sumy / cnt;

        cout << x << ' ' << y << endl;
    }
    
    return 0;
}