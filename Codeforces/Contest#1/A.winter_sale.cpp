///The winter sale began, and Mrs. Sarah wants to buy a T-shirt for her son. The T-shirt has a ticket that indicates a discount of X%
///and its price after the discount.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    float x, p;
    cin >> x >> p;

    float mp = p / (1 - (x / 100));     /// main price before discount.

    cout << fixed << setprecision(2) << mp << endl;

    return 0;
}