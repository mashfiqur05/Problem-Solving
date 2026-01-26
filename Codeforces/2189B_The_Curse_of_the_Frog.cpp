///   ***   ---   |||     In the name of ALLAH     |||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl '\n'
#define ll long long
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

// output
__int128 readInt128() {
    long long x;
    cin >> x;
    return (__int128)x;
}

void printInt128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(int CaseNo)
{
    int n;
    __int128 x;
    cin >> n;
    x = readInt128();

    vector<__int128> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        a[i] = readInt128();
        b[i] = readInt128();
        c[i] = readInt128();
    }

    vector<__int128> zeroRoll, oneRoll;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > 1)
        {
            __int128 tmp = a[i] * (b[i] - 1);
            zeroRoll.push_back(tmp);
            oneRoll.push_back(tmp + a[i] - c[i]);
        }
        else
        {
            oneRoll.push_back(a[i] - c[i]);
        }
    }

    sort(oneRoll.begin(), oneRoll.end(), greater<__int128>());

    __int128 initialScore = 0;

    for (auto u : zeroRoll)
    {
        if (initialScore + u >= x)
        {
            cout << 0 << endl;
            return;
        }
        initialScore += u;
    }

    if (initialScore >= x)
    {
        cout << 0 << endl;
        return;
    }

    __int128 nxtMove = oneRoll[0];
    if (nxtMove <= 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        __int128 baki = x - initialScore;
        __int128 ans = (baki + nxtMove - 1) / nxtMove; 
        printInt128(ans);
        cout << endl;
    }
}

int32_t main()
{
    fastio();

    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        solve(0);
    }

    return 0;
}
