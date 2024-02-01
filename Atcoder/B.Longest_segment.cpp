#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1123;
int x[mx];
int y[mx];

int main()
{
    optimize();
    fraction();

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    double ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double dis = sqrt(pow(y[i] - y[j], 2) + pow(x[i] - x[j], 2));
            ans = max (ans, dis);
        }
    }

    cout << setprecision(10) << ans << endl;

    return 0;
}