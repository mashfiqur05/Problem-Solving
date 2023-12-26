/*There are three cards with letters a,b,c placed in a row in some order. You can do the following operation at most once: Pick two cards, and swap them.
Is it possible that the row becomes abc after the operation? Output "YES" if it is possible, and "NO" otherwise.*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t)
    {
        char x, y, z;
        cin >> x >> y >> z;

        if (int(x) == 97 && int(y) == 98) cout << "YES" << endl;
        else if (int(x) == 97 && int(y) == 99) cout << "YES" << endl;
        else if (int(x) == 99 && int(z) == 97) cout << "YES" << endl;
        else if (int(x) == 98 && int(y) == 97) cout << "YES" << endl;
        else cout << "NO" << endl;

        t--;
    }

    return 0;
}