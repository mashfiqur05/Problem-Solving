/*Given multiple lines each line contains a number X which is a password. Print "Wrong" if the password is incorrect otherwise, print "Correct" and terminate the program.*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int pass;
    while (1)
    {
        cin >> pass;
        if (pass == 1999) 
        {
            cout << "Correct" << endl;
            break;
        }
        else cout << "Wrong" << endl;
        
    }

    return 0;
}