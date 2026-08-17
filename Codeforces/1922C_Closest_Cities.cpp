///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

/*
0 8 12 15 20
close[0] = 1
close[1] = 2
close[2] = 3
close[3] = 2
close[4] = 3

l = -1 -1 -1 2 2
r = 3 3 3 -1 -1

4 - 3 - 2 - 3
1 - 2 - 3 - 2 
*/
void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];


    vector<int> rightCost(n, 0);
    vector<int> leftCost(n, 0);


    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            rightCost[i + 1] = rightCost[i] + 1;
        }
        else
        {
            int leftDis = v[i] - v[i - 1];
            int rightDis = v[i + 1] - v[i];

            if (rightDis < leftDis)
                rightCost[i + 1] = rightCost[i] + 1;
            else
                rightCost[i + 1] = rightCost[i] + rightDis;
        }
    }


    for (int i = n - 1; i > 0; i--)
    {
        if (i == n - 1)
        {
            leftCost[i - 1] = leftCost[i] + 1;
        }
        else
        {
            int leftDis = v[i] - v[i - 1];
            int rightDis = v[i + 1] - v[i];

            if (leftDis < rightDis)
                leftCost[i - 1] = leftCost[i] + 1;
            else
                leftCost[i - 1] = leftCost[i] + leftDis;
        }
    }


    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        if (x < y)
            cout << rightCost[y] - rightCost[x] << endl;
        else
            cout << leftCost[y] - leftCost[x] << endl;
    }
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}