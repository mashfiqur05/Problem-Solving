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

char v[8][8];
bool rightDiagonal[16], leftDiagonal[16], row[8];
int ans = 0;

void fun (int currentCol)
{
    if (currentCol == 8)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (v[i][currentCol] == '.' && row[i] == 0 && rightDiagonal[i + currentCol] == 0 && leftDiagonal[i - currentCol + 7] == 0)
        {
            row[i] = 1;
            rightDiagonal[i + currentCol] = 1;
            leftDiagonal[i - currentCol + 7] = 1;

            fun (currentCol + 1);

            row[i] = 0;
            rightDiagonal[i + currentCol] = 0;
            leftDiagonal[i - currentCol + 7] = 0;
        }
    }
}

void solve (int CaseNo)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> v[i][j];

    fun (0);
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
        solve (tt);
    }

    return 0;
}