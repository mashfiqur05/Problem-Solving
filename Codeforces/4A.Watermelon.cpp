/// 800 rating.
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int weight;
    cin >> weight;

    if (weight % 2 == 0 && weight != 2) cout << "YES" << endl;  /// every even number except 2 can divide into 2 even number.
    else cout << "NO" << endl;

    return 0;
}