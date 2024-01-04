/// Given a number N. Print the maltiplication table of the number from 1 to 12.

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

    for (int i = 1; i <= 12; i++)
    {
        cout << n << " " << "*" << " " << i << " " << "=" << " " << n * i << endl;
    }
    

    return 0;
}