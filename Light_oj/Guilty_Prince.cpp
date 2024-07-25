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

const int N = 23;
char arr[N][N];
bool vis[N][N];
int m, n;
int cnt = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs (int x, int y)
{
    vis[x][y] = 1;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];

        if (a >= 1 && a <= n && b >= 1 && b <= m && vis[a][b] == 0 && arr[a][b] != '#')
        {
            dfs (a, b);
        }
    }
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> m >> n;
        int x, y;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }

        dfs (x, y);
        //cout << x << ' ' << y << endl;
        cout << "Case " << tt << ": " << cnt << endl;

        mem (vis, 0);
        cnt = 0;
    }
    
    return 0;
}