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
const int MOD = 1e9+7;


void testCases (int tt)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicant(n), apartment(m);
    for (int i = 0; i < n; i++) cin >> applicant[i];
    for (int i = 0; i < m; i++) cin >> apartment[i];

    sort (all (applicant));
    sort (all (apartment));

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (applicant[i] + k >= apartment[j] && applicant[i] - k <= apartment[j])
        {
            i++;
            j++;
            ans++;
        }
        else if (applicant[i] + k < apartment[j]) i++;
        else if (applicant[i] - k > apartment[j]) j++;
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}