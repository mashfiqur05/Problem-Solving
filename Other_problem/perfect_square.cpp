/// Find the given number is perfect square or not.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


int main()
{
    optimize();

    int number;
    int i = 1;
    cin >> number;
    bool perfectsquare = false;

    while((i * i) <= number){
        if((i * i) == number){
            cout << "PERFECT SQUARE" << endl;
            perfectsquare = true;
            break;
        }
            i++;
    }
    
    if(!perfectsquare){
        cout << "NOT PERFECT SQUARE" << endl;
    }

    return 0;
}