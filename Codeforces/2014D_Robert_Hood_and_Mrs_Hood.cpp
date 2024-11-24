///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, d, k;
        cin >> n >> d >> k;
        map<int, int> st, en;
        
        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;
            st[l]++;
            en[r]++;
        }

        int overlap = 0;
        for (int i = 1; i <= d; i++)
        {
            if (st.find (i) != st.end())
            {
                overlap += st[i];
            }
        }

        int ans1 = 1, ans2 = 1, mother = 0, brother = 0;
        mother = brother = overlap;

        for (int i = 2; i <= n - d + 1; i++)
        {
            if (st.find(i + d - 1) != st.end()) overlap += st[i + d - 1];           
            if (en.find(i - 1) != en.end()) overlap -= en[i - 1];

            if (overlap > brother)
            {
                brother = overlap;
                ans1 = i;
            }
            if (mother > overlap)
            {
                mother = overlap;
                ans2 = i;
            }
        }

        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}