#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
char grid[mx][mx];

int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    
    int x, y;
    int cnt = 0;
    cin >> x >> y;

    if (grid[x-1][y-1] != '.' && grid[x-1][y] != '.' && grid[x-1][y+1] != '.' && grid[x][y-1] != '.' && grid[x][y+1] != '.' && grid[x+1][y-1] != '.' && grid[x+1][y] != '.' && grid[x+1][y+1] != '.')
    {
        cout << "yes" << endl;
    }
    else cout << "no" << endl;

    return 0;
}