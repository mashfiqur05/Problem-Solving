///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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
const int N = 1000+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, m;
double dp[N][N];
bool vis[N][N];
/// dp[w][b] = winning probability of prince when prince moves and with w, b
/*
winning cond. 
prince move - take white.
prince move - take black - dragon take black - black mouse jump - prince move
                                              - white mouse jump - prince move
..
dp[w][b] = w/b + ((b/(w+b)) * ((b-1)/(w+b)) * ((b-2)/(w+b-2) + (w/(w+b-2))))

base case dp[i][0] = 1. i > 0
*/

double fun (int x, int y)
{
    if (x <= 0) return 0.0;
    if (y == 0) return 1.0;
    if (vis[x][y]) return dp[x][y];

    vis[x][y] = true;
    double w = 1.00 * x, b = 1.00 * y;
    double ret = w / (w+b);
    if (y >= 2) ret += (b / (w+b)) * (b-1)/(w+b-1) * ((w/(w+b-2)) * fun (w-1, b-2));
    if (y >= 3) ret += (b / (w+b)) * (b-1)/(w+b-1) * ((b-2)/(w+b-2) * fun (w, b-3));

    return dp[x][y] = ret;
}

void solve ()
{
    cin >> n >> m;
    cout << fun (n, m) << endl;
}


int32_t main()
{
    fastio();
    fraction();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}