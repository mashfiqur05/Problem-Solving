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

vector<int> primeFactor(int n) {
    
    vector<int> ret;
    while (n % 2 == 0) 
    {
        n = n/2; 
        ret.push_back (2);
    } 

    for (int i = 3; i*i <= n; i = i + 2) {
    
        while (n % i == 0) 
        {
            ret.push_back (i);
            n = n/i; 
        } 
    } 

    if (n > 2) ret.push_back (n);

    return ret;
}

void testCases (int tt)
{
    int a, b;
    cin >> a >> b;
    // cout << __gcd (a, b) << endl;
    int g = __gcd (a, b);

    int ans = 0;
    vector<int> primeFactorOfA = primeFactor (a);
    vector<int> primeFactorOfB = primeFactor (b);
    vector<int> primeFactorOfG = primeFactor (g);

    map<int, int> need, cnta, cntb;
    for (auto u : primeFactorOfG) need[u]++;
    for (auto u : primeFactorOfA) cnta[u]++;
    for (auto u : primeFactorOfB) cntb[u]++;

    for (auto u : need)
    {
        if (u.second > cnta[u.first] || u.second > cntb[u.first]) 
        {
            cout << -1 << endl;
            return;
        }
    }

    for (auto u : cnta)
    {
        if (u.first != 2 && u.first != 3 && u.first != 5 && !need[u.first])
        {
            cout << -1 << endl;
            return;
        }
        ans += (u.second - need[u.first]);
    }
    for (auto u : cntb)
    {
        if (u.first != 2 && u.first != 3 && u.first != 5 && !need[u.first])
        {
            cout << -1 << endl;
            return;
        }
        ans += (u.second - need[u.first]);
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