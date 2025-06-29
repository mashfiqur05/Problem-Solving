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
    int q;
    cin >> q;
    vector<int> bitCount (30, 0);
    while (q--)
    {
        int op, val;
        cin >> op >> val;
        if (op == 1)
        {
            bitCount[val]++;
            int cur = val;
            while (bitCount[cur] >= 3 && cur < 30)
            {
                bitCount[cur] -= 2;
                if (cur + 1 < 30) bitCount[cur+1]++;
                cur++;
            }
        }
        else 
        {
            int sum = val;
            for (int i = 29; i >= 0; i--)
            {
                if (pow(2, i) <= sum && bitCount[i])
                {
                    int ace = bitCount[i];
                    int canRemove = min((int)(sum / pow(2, i)), (int)bitCount[i]);
                    sum -= canRemove * pow(2, i);
                }
                // cout << sum << " " << i << endl;
            }
            if (sum == 0)
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
        testCases (tt);
    }

    return 0;
}