#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int n;
        cin >> n;
        /// Checking even or odd.
        if(n % 2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }


    return 0;
}