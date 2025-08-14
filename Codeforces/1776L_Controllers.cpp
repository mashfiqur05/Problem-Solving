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
    int n; cin >> n;
    string s; cin >> s;
    int plus = count (all (s), '+');
    int minus = count (all (s), '-');

    // (a - b)(x-y) - b (minus-plus)
    // x = no. of use + by a, y = no of use - by a

    int q;
    cin >> q;
    while (q--)
    {
        int a, b; 
        cin >> a >> b;
        // if (a < b) swap (a, b);
        int b_min_plus = b * (minus - plus);
        int dif = (a - b);
        
        // cout << b_min_plus << " " << dif << "---> " << b_min_plus / dif << endl;

        if (a == b)
        {
            if (plus == minus) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else 
        {
            if (b_min_plus % dif != 0) {cout << "NO" << endl; continue;}

            int p_minus_m = b_min_plus / dif;
            int low = max(0LL, -p_minus_m);         
            int high = min(minus, plus - p_minus_m); 

            if (low <= high)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}