/// 800 rating. /// math /// games /// HELLO 2024 contest.

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t, a, b;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;

        if ((a + b) % 2 == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}