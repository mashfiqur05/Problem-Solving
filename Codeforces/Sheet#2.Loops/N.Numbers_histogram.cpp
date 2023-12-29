/*Given 3 lines of input described as follow:First line contains a symbol S.
Second line contains a number N.Third line contains N numbers.For each number Xi in the N numbers print a new line that contains the symbol S repeated Xi time.*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int t, n;
    char ch;
    cin >> ch >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << ch;
        }
        cout << endl;
    }
    

    return 0;
}