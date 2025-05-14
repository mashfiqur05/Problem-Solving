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


void testCases (int tt)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt = count (all (s), 'W');
    if (cnt == 0)
    {
        cout << max (0LL, k * 2 - 1) << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            ans++;
            if (i - 1 >= 0 && s[i-1] =='W') ans++;
        }
    }

    int cur = 0, frst = 0;
    vector<int> block;
    while (s[frst] == 'L') frst++;
    for (int i = frst; i < n; i++)
    {
        if (s[i] == 'L') cur++;
        else 
        {
            if (cur != 0) block.push_back (cur);
            cur = 0;
        }
    }

    sort (all (block));
    for (int i = 0; i < block.size(); i++)
    {
        if (block[i] > k) 
        {
            ans += (k * 2);
            k = 0;
            break;
        }
        else 
        {
            ans += ((block[i] * 2) + 1);
            k -= block[i];
        }
    }

    if (k <= frst + cur) ans += (k * 2);
    else 
    {
        ans += ((frst + cur) * 2);
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}