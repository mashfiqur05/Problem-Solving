#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx], brr[mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i] >> brr[i];
        }

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (arr[i] <= 10)
            {
                res = max (res, brr[i]);
            }
        }

        int ans;
        for (int i = 1; i <= n; i++)
        {
            if (res == brr[i])
            {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}