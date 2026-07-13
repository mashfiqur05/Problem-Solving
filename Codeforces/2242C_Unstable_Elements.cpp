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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

void solve ()
{
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> cnt;
    for (auto u : v) cnt[u]++;

    vector<int> block;
    for (auto u : cnt) block.push_back(u.second);

    sort(all(block));

    int destroyed = 0;
    int remainingBlocks = block.size();
    int ans = 0;

    int i = 0;

    while (i < block.size())
    {
        int blockSize = block[i];

        // We check x = blockSize - 1
        int x = blockSize - 1;

        int currentSize =
            n - destroyed - x * remainingBlocks;

        if (currentSize <= k &&
            (k - currentSize) % remainingBlocks == 0)
        {
            ans++;
        }

        // Count blocks having this same size
        int j = i;

        while (j < block.size() &&
               block[j] == blockSize)
        {
            j++;
        }

        int numberOfBlocks = j - i;

        // These blocks will be destroyed afterward
        destroyed += blockSize * numberOfBlocks;

        remainingBlocks -= numberOfBlocks;

        i = j;
    }

    cout << ans << endl;
}



int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}