#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int code, quantity;
    cin >> code >> quantity ;   /// take input product code and quantity.
    
    /// using if else if loop store the product price in other variable.
    double price = 0.00;
    if (code == 1)
    {
        price = 4.00;
    }
    else if (code == 2)
    {
        price = 4.50;
    }
    else if (code == 3)
    {
        price = 5.00;
    }    
    else if (code == 4)
    {
        price = 2.00;
    }
    else price = 1.50;

    /// multiply the price and quantity.
    double total = price * quantity;
    
    printf("Total: R$ %.2lf\n", total);

    return 0;
}