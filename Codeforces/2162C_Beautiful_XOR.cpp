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

string decToBinary(long long n) {
    string s = "";
    for(int i = 0; i < 32; i++) {
        s = char((n & 1) + '0') + s;
        n >>= 1;
    }
    return s;
}

void solve (int CaseNo)
{
    int a, b; cin >> a >> b;
    int x = a ^ b;

    int msb_a = 1;
    while(msb_a <= a) msb_a <<= 1;
    msb_a >>= 1;

    int msb_b = 1;
    while(msb_b <= b) msb_b <<= 1;
    msb_b >>= 1;
    int pos_a = 31 - __builtin_clz(a);
    int pos_b = 31 - __builtin_clz(b);

    if (a == b)
    {
        cout << 0 << endl;
    }
    else if (pos_b > pos_a) cout << -1 << endl;
    else if (x <= a)
    {
        cout << 1 << endl << x << endl;
    }
    else 
    {
        vector<int> ans;
        string need = decToBinary(x);
        for (int i = 31; i >= 0; i--)
        {
            if (need[i] == '1')
            {
                int val = 1 << (31 - i);
                ans.push_back(val);
            }
        }

        cout << sz (ans) << endl;
        for (int i = 0; i < sz (ans); i++) cout << ans[i] << " "; cout << endl;
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