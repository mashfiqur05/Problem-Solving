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
const int N = 300+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, a[N];
double dp[N][N][N];
bool vis[N][N][N];

double fun (int i, int j, int k)
{
    if (i == 0 && j == 0 && k == 0) return 0;

    if (vis[i][j][k]) return dp[i][j][k];
    vis[i][j][k] = true;

    double ans = n;

    if (i > 0) ans += i * fun (i-1, j, k);
    if (j > 0) ans += j * fun (i+1, j-1, k);
    if (k > 0) ans += k * fun (i, j+1, k-1);

    ans /= (i+j+k);

    return dp[i][j][k] = ans;
}

void solve ()
{
    map<int, int> cnt;
    cin >> n;
    for (int i = 0; i < (int)n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    cout << fun (cnt[1], cnt[2], cnt[3]) << endl;
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