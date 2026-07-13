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
    int n;
        cin >> n;

        vector<int> a(n + 1);

        vector<int> pref1(n + 1, 0);
        vector<int> pref2(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];

            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];

            if(a[i] == 1)
            {
                pref1[i]++;
                pref2[i]++;
            }
            else if(a[i] == 2)
            {
                pref1[i]--;
                pref2[i]++;
            }
            else
            {
                pref1[i]--;
                pref2[i]--;
            }
        }

        vector<int> sufMax(n + 2, INT_MIN);

        sufMax[n - 1] = pref2[n - 1];

        for(int i = n - 2; i >= 1; i--)
            sufMax[i] = max(sufMax[i + 1], pref2[i]);

        bool ok = false;

        for(int i = 1; i <= n - 2; i++)
        {
            if(pref1[i] >= 0 && sufMax[i + 1] >= pref2[i])
            {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
}

/*5
1 3 3 1 1
i = 0, last = 4
cnt1 = 1, cnt2 = 0, cnt3 = 2
i = 1
cnt1 = 1, cnt2 = 0, cnt3 = 1
*/

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