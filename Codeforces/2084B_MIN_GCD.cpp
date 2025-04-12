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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int mn = *min_element (all (v));
    int mn_cnt = count (all (v), mn);

    vector<int> divisors;
    vector<bool> f;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % mn == 0) 
        {
            divisors.push_back (v[i] / mn);
            f.push_back (v[i] == mn);
        }
    }

    int gcd = 0;
    for (int i = 0; i < divisors.size(); i++)
    {
        gcd = (i == 0) ? divisors[i] : __gcd(gcd, divisors[i]);
    }
    
    if (gcd != 1 || divisors.size() < 2)
    {
        cout << "No" << endl;
        return;
    }

    vector<int> pre(divisors.size()), suf(divisors.size());

    pre[0] = divisors[0];
    for (int i = 1; i < divisors.size(); ++i) pre[i] = __gcd(pre[i - 1], divisors[i]);

    suf[divisors.size() - 1] = divisors[divisors.size() - 1];
    for (int i = divisors.size() - 2; i >= 0; --i) suf[i] = __gcd(suf[i + 1], divisors[i]);

    bool isPossible = 0;
    for (int i = 0; i < divisors.size(); ++i)
    {
        if (f[i])
        {
            int bade = 0;
            if (i > 0) bade = pre[i - 1];
            if (i < divisors.size() - 1)
            {
                if (bade == 0) bade = suf[i + 1];
                else bade = __gcd(bade, suf[i + 1]);
            }
            if (bade == 1)
            {
                isPossible = 1;
                break;
            }
        }
    }

    if (isPossible) cout << "Yes" << endl;
    else cout << "No" << endl;
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