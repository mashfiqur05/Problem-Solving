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
    int n, a, b; cin >> n >>a >> b;
    if (a + b > n+1 || (a == 1 && b == 1)) 
    {
        cout << "no" << endl;
        return;
    }

    vector<int> ans(n+1);
    if (a <= b)
    {
        int val = 1;
        for (int i = 1; i < a; i++) ans[i] = val++;
        ans[a] = n;
        for (int i = n; i > n - b + 2; i--) ans[i] = val++;
        ans[n-b+2] = n-1;
        for (int i = a+1; i < n - b + 2; i++) ans[i] = val++;
    }
    else 
    {
        int val = 1;
        for (int i = n; i > n - b + 1; i--) ans[i] = val++;
        ans[n-b+1] = n;
        for (int i = 1; i <= a-2; i++) ans[i] = val++;
        ans[a-1] = n-1;
        for (int i = a; i < n-b+1; i++) ans[i] = val++;
    }

    cout << "yes" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
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