/// Hello 2024 contest. 800 rating

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string s;
        
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+') cnt += 1;
            else  cnt = cnt - 1;
        }

        cout << abs(cnt) << endl;
    }

    return 0;
}