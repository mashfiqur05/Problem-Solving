/// Given a lowercase alphabet character. You have to print the next character in the alphabet.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    char a;
    cin >> a;

    int x = int(a);
    int y = x + 1;

    if (y == 123) cout << char(97) << endl;     /// ascii value of a is 97 and z = 122. The next letter to z is a.
    else cout << char(y) << endl;

    return 0;
}