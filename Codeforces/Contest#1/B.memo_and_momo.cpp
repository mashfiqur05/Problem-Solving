#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long long a, b, k;
    cin >> a >> b >> k;

    if ((a % k == 0) && (b % k == 0)) cout << "Both" << endl;
    else if (a % k == 0) cout << "Memo" << endl;
    else if (b % k == 0) cout << "Momo" << endl;
    else cout << "No One" << endl;

    return 0;
}