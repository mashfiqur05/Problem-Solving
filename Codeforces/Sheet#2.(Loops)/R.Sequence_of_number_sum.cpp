#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n, m;

    do
    {
        cin >> n >> m;
        int sum = 0;

        if (n <= 0 || m <= 0) break;
        else if (n > m)
        {
            for (int i = m; i <= n; i++)
            {
                sum += i;
                cout << i << " ";
            }
        }
        else 
        {
            for (int i = n; i <= m; i++)                
            {
                sum += i;
                cout << i << " ";
            }            
        }

        cout << "sum =" << sum << endl;  

    } while (n > 0 && m > 0);
    

    return 0;
}