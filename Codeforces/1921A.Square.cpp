#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int x[mx];
int y[mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];

        for (int i = 1; i < 4; i++)
        {
            if (x[0] == x[i])
            {
                int len = abs(y[i] - y[0]);
                int area = len * len;
                cout << area << endl;
            }
        }
    }

    return 0;
}