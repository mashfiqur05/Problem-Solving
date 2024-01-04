#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n, a, b, c;
    int count = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1)) count++;
    }

    cout << count;

    return 0;
}