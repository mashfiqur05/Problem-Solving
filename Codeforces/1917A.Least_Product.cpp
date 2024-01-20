/// constructive algorithms /// math /// *800

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e5+123;
int arr[mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        int n, product = 1, j =1;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++)
        {
            product *= arr[i];
        }

        if (product = 0) cout << '0' << endl;
        else if (product > 0) cout << '1' << endl << j << " " << '0' << endl;
        else cout << '0' << endl;
    }

    return 0;
}