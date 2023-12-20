///  Given a number N.Print the summation of the numbers that is between 1 and N(inclusive)

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
    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    
    cout << sum << endl;

    return 0;
}