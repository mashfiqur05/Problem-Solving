/// iven a number X. Determine in which of the following intervals the number X belongs to:[0,25], (25,50], (50,75], (75,100]

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double n;
    cin >> n;

    if (n >= 0 && n <= 25) cout << "Interval [0,25]" << endl;
    else if (n > 25 && n <= 50) cout << "Interval (25,50]" << endl;
    else if (n > 50 && n <= 75) cout << "Interval (50,75]" << endl;
    else if (n > 75 && n <= 100) cout << "Interval (75,100]" << endl;
    else cout << "Out of Intervals" << endl;

    return 0;
}