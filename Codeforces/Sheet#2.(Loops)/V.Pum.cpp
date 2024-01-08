/// Given a number N. Print N lines that describes PUM game.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int n;
    cin >> n;

    /// maximum number is 4*n and print pum where 4,8,12,16.......
    for (int j = 1; j <= (4 * n); j++)
    {
        if (j % 4 == 0) cout << "PUM" << endl;
        else cout << j << " ";
    }    

    return 0;
}