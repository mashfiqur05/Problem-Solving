/// Write a program which reads a sequence and prints it in the reverse order.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int a[1123];

int main()
{
    optimize();

    int n;
    int max = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {   
        cin >> a[i];
    }

    for (int i = 1, j = n; i < j; i++, j--)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
        if (i != n) cout << " ";    /// Print a single space character between adjacent elements (Note that your program should not put a space character after the last element).
    }
    cout << endl;
    
    return 0;
}