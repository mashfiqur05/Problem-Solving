#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t, bun, patties, cutlet, hamprice, chickenprice;
    cin >> t;

    int profit = 0;

    while (t--)
    {
        cin >> bun >> patties >> cutlet >> hamprice >> chickenprice;

        int mxprice, mnprice, mxpriceburger, mnpriceburger;

        if (hamprice > chickenprice)
        {
            mxprice = hamprice;
            mxpriceburger = 
        }
    }    

    return 0;
}