/// Given a string S. Print the origin string if it's not too long otherwise, print the special abbreviation.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t;
    string s;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> s;
        int length = 0;

        while (s[length] != '\0')
        {
            length++;
        }
        if (length > 10)
        {
            cout << s[0] << length-2 << s[length-1] << endl;
        }
        else cout << s << endl;
    }

    return 0;
}