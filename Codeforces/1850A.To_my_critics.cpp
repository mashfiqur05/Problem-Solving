#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        bool ans = 0;
        cin >> a >> b >> c;

        if (a+b >= 10 || a+c >= 10 || b+c >= 10) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}   