/// Given a number N, and N numbers, find maximum number in these N numbers

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n,number;
    int max = 0;
    cin >> n;

   for (int i = 1; i <= n; i++)
   {
        cin >> number;
        if (number > max) max = number;
   }
   
   cout << max << endl;

    return 0;
}