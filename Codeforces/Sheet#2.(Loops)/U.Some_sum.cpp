/// Given three numbers N, A, B. Print the summation of the numbers between 1 and N whose sum of digits is between A and B inclusive.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n, a, b;
    long long total = 0;
    cin >> n >> a >> b;

    /// find the number a to N.
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int temp = i;
        while (temp != 0)  /// find sum of the those number and total if their sum is between a to b.
        {
            short dig = temp % 10;
            sum += dig;
            temp /= 10;
        }
        if (sum >= a && sum <= b) total += i;
    }
    
    cout << total << endl;

    return 0;
}   