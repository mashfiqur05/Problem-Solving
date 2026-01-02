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


void solve (int CaseNo)
{
    int n, q; cin >> n >> q;
    vector<int> v(n+1), prefix0(n+1, 0), prefix1(n+1, 0),diffsum(n+1, 0), diff(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        prefix0[i] = prefix0[i-1] + (v[i] == 0);
        prefix1[i] = prefix1[i-1] + (v[i] == 1);

        diff[i] = v[i] != v[i - 1];
		diffsum[i] = diffsum[i - 1] + diff[i];
    }


    while (q--)
    {
        int l, r; cin >> l >> r;
        int cnt0 = prefix0[r] - prefix0[l-1], cnt1 = prefix1[r] - prefix1[l-1];
        if (cnt0 % 3 != 0 || cnt1 % 3 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int sum = cnt1 / 3 + cnt0 / 3;
            if (diffsum[r] - diffsum[l] == (r - l)) sum++;
            cout << sum << '\n';
        }
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}