#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t,n;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;

        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                cout << "*";
            }
            cout << endl;
        }
        if (i != t)
        {
            cout << endl;
        }  
    }

    return 0;
}