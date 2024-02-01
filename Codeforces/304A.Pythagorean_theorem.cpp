#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 2e8+123;
bool isperfectsquare[mx];

int main()
{
    optimize();

    int n, cnt = 0;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        isperfectsquare[k*k] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int value = i*i + j*j;

            if (isperfectsquare[value]) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}