/// Given N numbers. Count how many of these values are even, odd, positive and negative.
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n, x;
    cin >> n;
    int even = 0;
    int odd = 0;
    int pos = 0;
    int neg = 0;

    while (n) 
    {
        cin >> x;
        if (x % 2 == 0) even++;     /// checking even number.
        else  odd++;                /// if a number is not even that will be odd. 
        if (x > 0) pos++;           /// checking positive number or not.
        if (x < 0) neg++;           /// for zero we use another if loop for checking neg number.
        n--;
    }

    cout << "Even: " << even << endl << "Odd: " << odd << endl << "Positive: " << pos << endl << "Negative: " << neg << endl;

    return 0;
}