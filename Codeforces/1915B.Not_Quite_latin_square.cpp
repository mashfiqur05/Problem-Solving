/// bitmasks /// brute force /// implementation /// *800

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
char arr[mx][mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }

        int a = 0, b = 0, c = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 'A') a++;
                else if (arr[i][j] == 'B') b++;
                else if (arr[i][j] == 'C') c++;
            }
        }

        if (a == 2) cout << 'A' << endl;
        else if (b == 2) cout << 'B' << endl;
        else cout << 'C' << endl;

    }

    return 0;
}
