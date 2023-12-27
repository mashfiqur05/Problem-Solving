/// Given a number X. Determine if the number is prime or not

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
    int prime = 1;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) 
        {
            prime = 0;
            break;
        }
    }

    if (prime) cout << "YES";
    else cout << "NO";    
    

    return 0;
}