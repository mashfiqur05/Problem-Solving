#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int count = 0;
    for (int i= 1000; i >= 1; i--)
    {
        cout << i << " ";
        count++;
        if(count == 5)
        {
            cout << endl;
            count = 0;
        }
    }
    
    return 0;
}