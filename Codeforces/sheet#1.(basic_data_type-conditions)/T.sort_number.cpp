/// Given three numbers A, B, C. Print these numbers in ascending order followed by a blank line and then the values in the sequence as they were read.


#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b, c, i, j, k, temp;
    cin >> a >> b >> c;     /// take input three number.
    i = a, j = b, k = c;

   /// determine highest lowest value for accending.
    if (i > j)
    {
        temp = i;
        i = j;
        j = temp;
    }
    if (i > k)
    {
        temp = i;
        i = k;
        k = temp;
    }
    if (j > k)
    {
        temp = j;
        j = k;
        k = temp;
    }

   /// print the assending sequence and after a blank line print the given sequence.
   cout << i << endl << j << endl << k << endl << endl;
   cout << a << endl << b << endl << c << endl;

    return 0;
}