#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 30;
int cnt[mx];

int main()
{
    optimize();

    string s;
    cin >> s;

    int i = 0;
    while (i < s.length())
    {
        int index = s[i] - 'a';
        cnt[index]++;
        i++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            char c = i + 'a';
            cout << c << " : " << cnt[i] << endl; 
        }
    }

    return 0;
}