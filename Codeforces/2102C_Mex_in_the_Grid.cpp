///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

void generateSpiral(int n) 
{
    int size = ceil(sqrt(n));
    if (size % 2 == 0) size++;  

    vector<vector<int>> grid(size, vector<int>(size, -1));

    int x = size / 2;
    int y = size / 2;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int dir = 0;

    int steps = 1, count = 0;
    grid[y][x] = count++;

    while (count < n)
    {
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < steps; ++j)
            {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < size && y >= 0 && y < size && count < n)
                {
                    grid[y][x] = count++;
                }
            }
            dir = (dir + 1) % 4;
        }
        steps++;
    }

    // Find non-empty bounds
    int top = size, bottom = 0, left = size, right = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (grid[i][j] != -1)
            {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }

    int width = to_string(n - 1).length();
    for (int i = top; i <= bottom; ++i)
    {
        for (int j = left; j <= right; ++j)
        {
            if (grid[i][j] == -1)
                cout << setw(width) << " " << " ";
            else
                cout << setw(width) << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void testCases(int tt)
{
    int n;
    cin >> n;

    generateSpiral(n * n);
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }

    return 0;
}