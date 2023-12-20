/// Given a Number N corresponding to a person's age (in days). Print his age in years, months and days, followed by its respective message "years", "months", "days".

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

    int year = n / 365;
    n = n - 365 * year;
    int month = n / 30;
    int day = n - 30 * month;
     
    cout << year << " " << "years" << endl << month << " " << "months" << endl << day << " " << "days";

    return 0;
}