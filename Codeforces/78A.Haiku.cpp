/// implementation /// strings /// *800

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

bool isvowel (char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    optimize();

    vector<string> v;
    int cnt[] = {5, 7, 5};

    for (int i = 0; i < 3; i++)
    {
        char c;
        string s;
        cin >> c;
        getline (cin, s);
        s = c + s;

        v.push_back(s);
    }

    for (int i = 0; i < 3; i++)
    {
        int vowel = 0;
        
        for (auto u : v[i])
        {
            if (isvowel(u)) vowel++;
        }

        if (vowel != cnt[i]) return cout << "NO" << endl,0;
    }

    cout << "YES" << endl;
}