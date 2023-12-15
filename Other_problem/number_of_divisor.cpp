/// Find the total number of Divisor of a given number...

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


int main()
{
    optimize();

    int number;
    cin >> number;
    int i = 1;
    int count = 0;

    while(i * i <= number){
        if(number % i == 0){
            count++;
            if(i != (number / i)){
                count++;
            }
        }
            i++;
    }

    cout << count << endl;
    return 0;
}