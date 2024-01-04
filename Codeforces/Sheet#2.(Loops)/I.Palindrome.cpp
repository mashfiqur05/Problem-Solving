/*Given a number N.Print 2 lines that contain the following respectively:1.Print N in a reversed order and not leading zeroes.
2.If N is a palindrome number print "YES" otherwise, print "NO.*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n;
    cin >> n;

    int original = n;
    int rev = 0;
    int temp = 0;

    while (n != 0)
    {
        temp = n % 10;
        rev = rev * 10 + temp;
        n = n / 10;
    }
    cout << rev << endl;
    if (original == rev) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}