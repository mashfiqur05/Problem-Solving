/*Given a letter X. If the letter is lowercase print the letter after converting it from lowercase letter to uppercase letter. 
Otherwise print the letter after converting it from uppercase letter to lowercase letter*/

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

    if (int(a) >= 65 && int(a) <= 90)   /// ascii value of A=65, Z=90, a=97.
    {
        int b = int(a) + 32;    /// difference between 'a' and 'A' in ASCII is 32 .
        cout << char(b);
    }
    else 
    {
        int b = int(a) - 32;
        cout << char(b);
    }

    return 0;
}