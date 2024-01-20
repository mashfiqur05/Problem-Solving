#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


int main()
{
    optimize();

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string s, f;
        int scnt = 0, fcnt = 0, move = 0;

        cin >> s >> f;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') scnt++;
            if (f[i] == '1') fcnt++;
        }

        if (fcnt <= scnt)
        {
            move = scnt - fcnt;
            for (int i = 0; i < n; i++)
            {
                if (f[i] == '1' && s[i] == '0') move++;
            }
        }
        else
        {
            move = fcnt - scnt;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1' && f[i] == '0') move++;
            }
        }

        cout << move << endl;
    }

    return 0;
}