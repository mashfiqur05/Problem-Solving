///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(15); cout.setf(ios::fixed,ios::floatfield);
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

int prob = 0;

void subsetGenerate (int n, string go, int need)
{
    if (go.size() == n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++) 
        {
            if (go[i] == '+') sum++;
            else sum--;
        }
        if (sum == need) prob++;

        return;
    }

    string s1 = go + '+';
    string s2 = go + '-';
    subsetGenerate (n, s1, need);
    subsetGenerate (n, s2, need);
}

void testCases (int tt)
{
    string a, b;
    cin >> a >> b;
    ll total1 = 0, total2 = 0, notFound = 0;
    for (auto u : a)
    {
        if (u == '+') total1++;
        else total1--;
    }
    for (auto u : b)
    {
        if (u == '+') total2++;
        else if (u == '-') total2--;
        else notFound++;
    }

    int need = total1 - total2;
    subsetGenerate (notFound, "", need);

    fraction();
    double ans = 1.00 * prob / (1 << notFound);

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