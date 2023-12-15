#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double n;
    cin >> n;   /// input the floating number.

    /// if else loop for checking condition.
    if (n >= 0 && n <= 25)
    {
        cout << "Intervalo [0,25]" << endl;
    }
    else if (n > 25 && n <= 50)
    {
        cout << "Intervalo (25,50]" << endl;
    }
    else if (n > 50 && n <= 75)
    {
        cout << "Intervalo (50,75]" << endl;
    }
    else if (n > 75 && n <= 100)
    {
        cout << "Intervalo (75,100]" << endl;
    }
    else cout << "Fora de intervalo" << endl;

    return 0;
}   